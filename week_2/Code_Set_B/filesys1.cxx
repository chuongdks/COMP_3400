#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    fs::path const p{ "/usr/local/bin/cmd" };

    // Approuch 1 with p.begin() and p.end()
    for (auto i = p.begin(); i != p.end(); ++i) {
        std::cout << i->generic_string() << '\n';
    }
    
    // Approach 2: ref to p
    for(auto &e : p) {
        std::cout << e << '\n';
    }
}
