#include <map>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  using namespace std;

  map<string,unsigned> freq_hist;

  for (string word; cin >> word; )
    ++freq_hist[word];

  vector vals(
    freq_hist.begin(),
    freq_hist.end()
  );

  for (auto const& entry : vals)
    cout << entry.first << ' ' << entry.second << '\n';
}
