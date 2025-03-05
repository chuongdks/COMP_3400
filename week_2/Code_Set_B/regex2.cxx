#include <iomanip>                // for std::quoted
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

int main()
{
  using namespace std;
  regex re{ R"end(([[:alnum:]]+)(\.txt))end" };
  if (string s; getline(cin,s)) {
    string result;
    regex_replace(back_inserter(result), s.begin(), s.end(), re, "$1.dat$2");
    cout << "Result: " << std::quoted(result) << '\n';
  }
}
