#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

// Use Vector of Maps instead of Vector of Pairs
vector<map<string, string>> readOrdersFromFile(const string& filename) {
    vector<map<string, string>> ordersVector;
    ifstream inputFile(filename);
    string line;
    int lineNumber = 0;

    if (!inputFile) {
        cerr << "No file supplied Error when opening file: " << filename << "\nPlease Exit the program and try again\n";
        return ordersVector;  // Return empty vector on error
    }

    // https://stackoverflow.com/questions/43865943/read-line-textfile-and-split-if-it-got-comma
    while (getline(inputFile, line)) {
        lineNumber++;
        istringstream iss(line);
        string trackingID, status, extraValue;

        try { // Try to extract value from the input line
            if (getline(iss, trackingID, '\t') && getline(iss, status, '\t')) {  
                // If an extra value is detected      
                if (getline(iss, extraValue)) {
                    throw runtime_error("Invalid content at line: " + to_string(lineNumber));
                }

                // Check for missing TrackingId or Status
                if (trackingID.empty() || status.empty()) {
                    throw runtime_error("Missing value at line: " + to_string(lineNumber));
                }

                // Assign TrackingId and Status as normal
                trackingID = trackingID.substr(1, trackingID.size() - 2);       // Remove quotes using substring https://www.baeldung.com/java-remove-start-end-double-quote
                status = status.substr(1, status.size() - 2);                   // Remove quotes
    
                map<string, string> singleOrderMap;                             // Create new map for each key value pair
                singleOrderMap[trackingID] = status;                            // Update and Insert new map this way: https://en.cppreference.com/w/cpp/container/map (Example part)
    
                ordersVector.push_back(singleOrderMap);                         // Push that map into the vector
            }
            else {
                throw runtime_error("Invalid content at line " + to_string(lineNumber));
            }
        }
        catch (const exception& e){
            clog << e.what() << endl;  // Print error message
        }

    }

    inputFile.close();
    return ordersVector;
}

// 2. Update the status of an Order 
void updateOrderStatus(vector<map<string, string>>& orders, const string& trackingID, const string& updateStatus) {
    for (auto& order : orders) {                   
        // https://en.cppreference.com/w/cpp/container/map/find (return map.end() if not found)               
        if (auto search = order.find(trackingID); search != order.end()) {                      // order.find(trackingID) != order.end()
            order[trackingID] = updateStatus;
            cout << "Order: " << search->first << " updated to: " << search->second << endl;
            return;
        }
    }
    cout << "Cannot find Order number. Please check again" << endl;
}

// 3. Add new Order with a new Status
void addNewOrder(vector<map<string, string>>& orders, const string& trackingID, const string& status) {
    for (const auto& order : orders) {
        // https://en.cppreference.com/w/cpp/container/map/find (return map.end() if not found)               
        if (auto search = order.find(trackingID); search != order.end()) {                      // order.find(trackingID) != order.end()
            cout << "Order ID is already existed. Please check again" << endl;
            return;
        }        
    }
    
    map<string, string> singleOrderMap;                             // Create new map for each key value pair
    singleOrderMap[trackingID] = status;                            // Update and Insert new map this way: https://en.cppreference.com/w/cpp/container/map (Example part)

    orders.push_back(singleOrderMap);                         // Push that map into the vector
    cout << "New order added successfully." << endl;
}

// 4. Search for Order ID then display status
void searchOrder(const vector<map<string, string>>& orders, const string& trackingID) {
    for (const auto& order : orders) {
        // https://en.cppreference.com/w/cpp/container/map/find (return map.end() if not found)               
        if (auto search = order.find(trackingID); search != order.end()) {                      // order.find(trackingID) != order.end()
            cout << "Order Status: " << search->second << endl;
            return;
        }
    }
    cout << "Order Not Found." << endl;
}

// Function to write orders to file from vector
void writeOrdersToFile(const string& filename, const vector<map<string, string>>& orders) {
    ofstream outf(filename);
    if (!outf) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }

    // using for each
    for (const auto& order : orders) {
        for (const auto& pair : order) {
            outf << "\"" << pair.first << "\"\t\"" << pair.second << "\"" << endl;
        }
    }

    // // Using iterator: https://stackoverflow.com/questions/14070940/how-can-i-print-out-c-map-values
    // for (auto orderIt = orders.begin(); orderIt != orders.end(); ++orderIt) { 
    //     for (auto it = orderIt->begin(); it != orderIt->end(); ++it) {  
    //         outf << "\"" << it->first << "\"\t\"" << it->second << "\"" << endl;
    //     }
    // }

    outf.close();
}

int main(int argc, char* argv[]) {
    string filename = "";

    if (argc != 2) {
        cerr << "No Input file Supplied.\nEnter the file name: ";
        cin >> filename;
    }
    else {
        filename = argv[1];
    }

    

    // Step 2: Convert the map to a vector of pairs
    vector<map<string, string>> ordersVector = readOrdersFromFile(filename);

    int choice;
    while (true) {
        cout << "\nUberEats Order Tracking System\n";
        cout << "1. Search Order\n";
        cout << "2. Update Order Status\n";
        cout << "3. Add New Order\n";
        cout << "4. Print the Tracking ID and Status on screen\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int mapNum = 1;
        string trackingID, status;
        switch (choice) {
            case 1:
                cout << "Enter Tracking ID: ";
                cin >> trackingID;
                searchOrder(ordersVector, trackingID);
                break;
            case 2:
                cout << "Enter Tracking ID: ";
                cin >> trackingID;
                cout << "Enter New Status: ";
                cin.ignore();                                       // https://www.geeksforgeeks.org/cin-ignore-function-in-cpp/
                getline(cin, status);
                updateOrderStatus(ordersVector, trackingID, status);
                writeOrdersToFile(filename, ordersVector);
                break;
            case 3:
                cout << "Enter New Tracking ID: ";
                cin >> trackingID;
                cout << "Enter Status: ";
                cin.ignore();                                       // https://www.geeksforgeeks.org/cin-ignore-function-in-cpp/
                getline(cin, status);
                addNewOrder(ordersVector, trackingID, status);
                writeOrdersToFile(filename, ordersVector);
                break;
            case 4:
                for (const auto& orderMap : ordersVector) {
                    cout << "Map number: " << mapNum++ << endl;
                    for (const auto& pair : orderMap) {
                        cout << "\tTracking ID: " << pair.first << ", Status: " << pair.second << endl;
                    }
                    cout << "\n";
                }
                mapNum = 0;
                break;        
            case 5:
                cout << "Exit the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Choose from 1 to 4\n";
        }
    }
}
