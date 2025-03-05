// C++ Program to implement
// template Array class
#include <iostream>
#include <vector>
using namespace std;

/* Enter 5 number: 
Have 2 vector: vector of int, vector of double
implement of product of all the pro
*/

template<typename Sequence, typename Value>
Value product(const Sequence& s, Value v)
{
    for (const auto& x : s)
    v*=x;
    return v;
}

void user(vector<int>& vi, vector<double>& ld)
{
    int x = product(vi,0); // the sum of a vector of ints (add ints)
    double d = product(vi,0.0); // the sum of a vector of ints (add doubles)
    double dd = product(ld,0.0); // the sum of a list of doubles
}

int main(int argc, char* argv[]) {
    cout << "Enter 5 numbers: \n";
    vector<int> vi(5);
    
    for (int i = 0; i < 5; i++)
        cin >> vi[i];

    vector<double> ld(vi.begin(), vi.end()); // Convert int vector to double

    user(vi, ld); // Call the user function to use product()

    return 0;

    
}