#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

// // Define type aliases for clarity
// using OrderMap = map<string, string>;
// using OrderVector = vector<pair<string, string>>;

// Function to read from txt file and put id, status into the Map
map<string, string> readOrdersFromFile(const string& filename) {
    map<string, string> orders;
    ifstream inputFile(filename);
    string line;

    // check error when reading file
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        return orders;          // cant return 1 cuz map
    }

    // https://stackoverflow.com/questions/43865943/read-line-textfile-and-split-if-it-got-comma
    while (getline(inputFile, line)) {
        // std::cout << line << '\n';                                   // debug
        istringstream iss(line);
        string trackingID, status;

        // extract line until delimiter '\t' is found
        if (getline(iss, trackingID, '\t') && getline(iss, status)) {        
            trackingID = trackingID.substr(1, trackingID.size() - 2);   // Remove quotes using substring https://www.baeldung.com/java-remove-start-end-double-quote
            status = status.substr(1, status.size() - 2);               // Remove quotes        
            orders[trackingID] = status;                                // Update and Insert new map this way: https://en.cppreference.com/w/cpp/container/map (Example part)

            // std::cout << trackingID << '\n' << status << "\n";       // debug
        }
    }
    inputFile.close();
    return orders;
}

// Store the package info (Map info) to Vector of Pairs
vector<pair<string, string>> mapToVector(const map<string, string>& orders) {
    vector<pair<string, string>> orderVector;
    for (const auto& order : orders) {                                  // (https://www.scaler.com/topics/vector-pair-in-cpp/ in Iterator Techniques)
        orderVector.push_back(make_pair(order.first, order.second));    // https://www.scaler.com/topics/vector-pair-in-cpp/
    }
    return orderVector;
}

// // Convert Vector back to Map
// map<string, string> vectorToMap(const OrderVector& orderList) {
//     map<string, string> orders;
//     for (const auto& order : orderList) {
//         orders[order.first] = order.second;
//     }
//     return orders;
// }

// 2. Update the status of an Order 
void updateOrderStatus(vector<pair<string, string>>& orders, const string& trackingID, const string& updateStatus) {
    for (auto& order : orders) {                                        // (https://www.scaler.com/topics/vector-pair-in-cpp/ in Iterator Techniques)
        if (order.first == trackingID) {
            order.second = updateStatus;
            cout << "Order: " << order.first << " updated to: " << order.second << endl;
            return;
        }
    }
    cout << "Cannot find Order number. Please check again" << endl;
}

// 3. Add new Order with a new Status
void addNewOrder(vector<pair<string, string>>& orders, const string& trackingID, const string& status) {
    for (const auto& order : orders) {
        if (order.first == trackingID) {
            cout << "Order ID is already existed. Please check again" << endl;
            return;
        }
    }
    orders.push_back(make_pair(trackingID, status));
    cout << "New order added successfully." << endl;
}

// 4. Search for Order ID then display status
void searchOrder(const vector<pair<string, string>>& orders, const string& trackingID) {
    for (const auto& order : orders) {
        if (order.first == trackingID) {
            cout << "Order Status: " << order.second << endl;
            return;
        }
    }
    cout << "Order Not Found." << endl;
}

// Function to write orders to file from vector
void writeOrdersToFile(const string& filename, const vector<pair<string, string>>& orders) {
    ofstream outf(filename);
    if (!outf) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }

    for (const auto& order : orders) {
        outf << "\"" << order.first << "\"\t\"" << order.second << "\"" << endl;
    }
    outf.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string filename = argv[1];

    // Step 1: Read orders from file into a map
    map<string, string> ordersMap = readOrdersFromFile(filename);

    // Step 2: Convert the map to a vector of pairs
    vector<pair<string, string>> ordersVector = mapToVector(ordersMap);

    int choice;
    while (true) {
        cout << "\nUberEats Order Tracking System\n";
        cout << "1. Search Order\n";
        cout << "2. Update Order Status\n";
        cout << "3. Add New Order\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

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
                cout << "Exit the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Choose from 1 to 4\n";
        }
    }
}
