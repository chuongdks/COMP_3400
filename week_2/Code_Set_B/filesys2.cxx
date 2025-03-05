#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
  const fs::path p{ "/usr/local/bin/" };

  auto i = p.end();  // i is a past-the-end iterator
  --i;               // Move i to the last component

  if (i != p.begin()) {
    std::cout << "Last component: " << i->generic_string() << '\n';
  } else {
    std::cout << "Path is empty or only contains a root.\n";
  }

  if (!p.empty() && (--p.end())->empty())
    std::cout << p << " has a trailing directory separator\n";
}
