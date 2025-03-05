// C++ program to overload the binary operator +
// This program adds two complex numbers

#include <iostream>
using namespace std;

class Complex {
    private:
        float real;
        float img;

    public:
        // constructor to initialize real and img to 0
        Complex() {
            real = 0;
            img = 0;
        }

        Complex(float real, float img) {
            this->real = real;
            this->img = img;
        }

        // // overload the + operator with 2 arguemnts
        // friend Complex operator * (const Complex& obj1, const Complex& obj2) {
        //     Complex temp;
        //     temp.real = obj1.real * obj2.real;
        //     temp.img = obj1.img * obj2.img;
        //     return temp;
        // }

        // overload the + operator
        Complex operator * (const Complex& obj1) {
            Complex temp;
            temp.real = real * obj1.real;
            temp.img = img * obj1.img;
            return temp;
        }

        void display() {
            cout << "Output Complex number: " << real << "+" << img << "i";
        }
};

int main() {
    Complex c1(1.0f, 2.0f);
    Complex c2(2.0f, 3.0f);
    Complex c3(3.0f, 3.0f);

    // calls the overloaded + operator
    Complex result = c1 * c2 * c3;
    result.display();

    return 0;
}