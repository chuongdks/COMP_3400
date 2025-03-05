#include <iostream>
#include <map>
using namespace std;

struct Student {
    string name;
    int phoneNumber;
};

map<int, Student> classroom = {
    {1, {"Andy", 12345}}, 
    {2, {"Bob", 52343}}, 
    {110109379, {"Chuong Hoang Pham", 7338}}, 
    {4, {"Dan", 1223345}}, 
    {5, {"Emily", 17673}}
};


// Function to print students
void print_students(const map<int, Student>& classroom) {
    for (const auto& entry : classroom) {
        cout << "ID: " << entry.first 
             << " Name: " << entry.second.name 
             << " Phone: " << entry.second.phoneNumber << "\n";
    }
}

int main() {
    print_students(classroom);
    return 0;
}