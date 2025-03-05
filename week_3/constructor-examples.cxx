#include <iostream>
#include <utility>

struct Type 
{
    int* p;

    Type() : p(new int(42)) { 
        std::cout << "Default constructor: " << *p << std::endl; 
    } // default constructor

    Type(int i) : p(new int(i)) { 
        std::cout << "Int constructor: " << *p << std::endl; 
    } // a constructor

    Type(const Type& t) : p(new int(*t.p)) { 
        std::cout << "Copy constructor: " << *p << std::endl; 
    } // copy constructor

    Type(Type&& t) : p(t.p) { 
        t.p = nullptr; 
        std::cout << "Move constructor" << std::endl; 
    } // move constructor

    ~Type() { 
        if (p) {
            std::cout << "Destructor: " << *p << std::endl;
            delete p; 
        } else {
            std::cout << "Destructor: nullptr" << std::endl;
        }
    } // destructor
};

int main() {
    Type a;                    // Default constructor
    Type b = a, c(a);          // Copy constructor (b and c)
    Type d = std::move(a);     // Move constructor (d)
    Type e(std::move(b));      // Move constructor (e)
    Type f{Type(15)};            // Move constructor (f)
    Type y(59), z(60);         // Int constructor (y and z)

    return 0;
}
