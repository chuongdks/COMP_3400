#include <ostream>
std::ostream& operator <<(std::ostream& os, MYTYPE const& t)
{
  // Code to write out type here...
  os << t.whatever; // i.e., write necessary code here
  return os;
}
