#include <iostream>

struct foo 
{ 
  int i;

  // Normal one with this + argument
  auto operator + (foo const& rhs) const // argument is the second operand
  {
    return foo{ this->i + rhs.i };
  }

  // Unary operator+ overload
  auto operator + () const // notice there is no argument
  {
    return foo{ this->i + 3 };
  }

  // Unary operator with friend
  friend auto operator + (foo const& a)
  {
    return foo{ a.i + 3 };
  }

  // Friend function for binary operator+
  friend auto operator + (foo const& a, foo const& b)
  {
    return foo{ a.i + b.i };
  }

  // Pre-fix operator
  foo& operator ++ () // refer the original foo
  {
    ++this->i;      // Increment the member variable `i`
    return *this;   // Return the current object (*this) by reference
  }

  // Post-fix oeprator
  foo operator ++ (int) // postfix operator
  {
    const foo retval{*this}; // Make a copy of the current object
    this->operator++();      // Call the prefix `operator++` to increment the object
    return retval;           // Return the copy (unmodified object)
  }

};

// Binary overload free function
auto operator + (foo const& a, foo const& b) // foo operator+(foo const& a
{
  return foo{ a.i + b.i };
}

// Unary overload free function
auto operator + (foo const& a)
{
  return foo{ a.i + 3 };
}

using namespace std;


int main()
{
    // Binary Operator Test
    foo a{10}, b{20};
    foo c = a + b;    // Works fine
    // c.i = 50;         // Allowed (c is not const)
    std::cout << "c.i = " << c.i << '\n'; // Output: 30
    
    const foo d{30};
    foo e = d + b;    // Also works because operator+ is const
    std::cout << "e.i = " << e.i << '\n'; // Output: 50

    // Unary Operator Test
    foo a{5};
    foo b = +a; // Calls the unary operator+
    
    std::cout << "a.i = " << a.i << '\n'; // Output: 5
    std::cout << "b.i = " << b.i << '\n'; // Output: 8 (5 + 3)

    // Pre-fix
    foo a{5};
    ++a;       // Calls prefix operator++
    std::cout << a.i; // Output: 6

    // Post-fix
    foo a{5};
    foo b = a++; // Calls postfix operator++
    std::cout << a.i; // Output: 6 (incremented)
    std::cout << b.i; // Output: 5 (original value)

    return 0;
}


