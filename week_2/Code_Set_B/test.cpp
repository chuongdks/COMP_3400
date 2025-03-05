#include <filesystem>
#include <iostream>
#include <regex>
#include <string>

namespace fs = std::filesystem;
using namespace std;
using namespace std::literals::chrono_literals;

// https://en.cppreference.com/w/cpp/filesystem/directory_entry/last_write_time
std::string to_string(const std::filesystem::file_time_type& ftime)
{
    #if __cpp_lib_format
        return std::format("{:%c}", ftime);
    #else
        std::time_t cftime = std::chrono::system_clock::to_time_t(
            std::chrono::file_clock::to_sys(ftime));
        std::string str = std::asctime(std::localtime(&cftime));
        str.pop_back(); // rm the trailing '\n' put by `asctime`
        return str;
    #endif
}

int main(int argc, char *argv[])
{
    try
    {
        regex re { R"([[:alnum:]]+\.pptx)", regex_constants::ECMAScript | regex_constants::icase};

        // range-based for loop...
        for (const auto& entry : fs::directory_iterator {
                    (argc > 1 ? argv[1] : "./"),
                    fs::directory_options::skip_permission_denied
                }
            )
        {
            const auto currentTime = std::chrono::file_clock::now() - (5*30h);      // current time is within 30hrs + 5 days
            string fileName = entry.path().filename();                              // https://en.cppreference.com/w/cpp/filesystem/path/filename
            fs::file_time_type fileLastModified = entry.last_write_time();
            
            if (regex_match(fileName, re) && (fileLastModified >= currentTime)) { // 
                cout << "FOUND: " << entry.path().generic_string() << " " << to_string(fileLastModified) << '\n';
            }
            else {
                cout << "Old files or not a power point file:" << entry.path().generic_string() << '\n';
            }
        }
    }

    catch (fs::filesystem_error& ex)
    {
        std::clog << "EXCEPTION: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::clog << "EXCEPTION: unknown\n";
        return 2;
    }
    
    return 0;
}
