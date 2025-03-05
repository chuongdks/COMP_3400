#include <algorithm>
#include <map>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

int main()
{
  using namespace std;

  using mymap_type = map<string,unsigned>;

  mymap_type freq_hist;

  for (string word; cin >> word; )
    ++freq_hist[word];

  vector vals(
    freq_hist.begin(),
    freq_hist.end()
  );

  auto const num = count_if(freq_hist.begin(), freq_hist.end(),
    [](auto const& entry)
    {
      return entry.second >= 2;
    }
  );

  cout << "num >= 2 is " << num << '\n';
  for (auto const& entry : vals)
    cout << entry.first << ' ' << entry.second << '\n';

  auto vals2 = vals;

  auto pos = copy_if(
    freq_hist.begin(), freq_hist.end(),
    vals2.begin(),
    [](auto const& entry)
    {
      return entry.second >= 2;
    }
  );

  //vals2.erase(pos,vals2.end());

  for (auto const& entry : vals2)
    cout << "vals2: " << entry.first << ' ' << entry.second << '\n';

}
