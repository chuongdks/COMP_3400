template <typename T, typename U>
auto my_func(T t, U u) -> decltype(t+u) // return type is whatever type t+u is
{
  return t+u;
}

int main() {
    cout << my_func(3, 4) << endl;           // Both int: result is int (7)
    cout << my_func(3, 4.5) << endl;         // int + double: result is double (7.5)
    cout << my_func(string("Hi, "), "there") << endl; // string + const char*: result is string ("Hi, there")
    return 0;
}