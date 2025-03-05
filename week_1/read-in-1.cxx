#include <istream>
std::istream& operator >>(std::istream& is, MYTYPE& t)
{
  // Code to read in type here...
  is >> t.whatever; // i.e., write necessary code here
  return is;
}
