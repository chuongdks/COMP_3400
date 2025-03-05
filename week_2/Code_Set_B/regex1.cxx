#include <iostream>
#include <regex>
#include <string>

int main()
{
  using namespace std;
  regex re{ R"( [[:alnum:]]+\.txt )" };
  if (string s; getline(cin,s) && regex_match(s, re))
    cout << "Matched.\n";
  else
    cout << "Not matched.\n";
}
