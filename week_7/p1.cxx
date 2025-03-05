#include <map>
#include <iostream>
#include <string>

int main()
{
  using namespace std;

  map<string,unsigned> freq_hist;

  for (string word; cin >> word; )
    ++freq_hist[word];

  // output the hist...
  auto i = freq_hist.begin();
  auto i_end = freq_hist.end();
  for (; i != i_end; ++i)
    cout << "(" << i->first << ' ' << i->second << ")\n";
}
