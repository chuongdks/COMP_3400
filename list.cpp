#include <iostream>
#include <list>
using namespace std;

struct Student {
    string name;
    int id;
    int phoneNumber;
};

ostream& operator<<(ostream& out, const Student& c)
{
    return out << "Name: " << c.name << " ID: " << c.id << " Phone number: " << c.phoneNumber;;
}

istream& operator>>(istream& in, Student& c)
{
    cout << "Enter name: ";
    in >> ws;
    getline(in, c.name);
    
    cout << "Enter ID: ";
    in >> c.id;
    
    cout << "Enter phone number: ";
    in >> c.phoneNumber;
    
    return in;
}

// Create a vector called cars that will store strings
list<Student> classroom = {
    {"Andy", 1, 12345}, 
    {"Bob", 2, 54521}, 
    {"Chuong Hoang Pham", 110109379, 7338},
    {"Dan", 4, 69373},
    {"Emily", 5, 19374}
};

// THis function does not work cuz we cant access list index    
// void print_student(const list<Student>& student) {
//     for (int i = 0; static_cast<long unsigned int>(i)!=student.size(); ++i) {
//         cout << student[i] <<"\n";
//     }
// }

// void input() {
//     for (Student e:cin>>e;) {
//         Student e;
//         cin >> e;
//     }
// }

int main() {
    // print_student(classroom);

    return 0;
}
