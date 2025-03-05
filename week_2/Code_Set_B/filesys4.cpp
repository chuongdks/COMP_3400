#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
using namespace std::literals::chrono_literals;
using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        auto i = fs::recursive_directory_iterator {
            (argc > 1 ? argv[1] : "/var/run"),
            fs::directory_options::skip_permission_denied
        };
        auto i_end = fs::recursive_directory_iterator{};

        // traditional for loop...
        //   * requires using explicit iterator object
        //   * range-based for loop does not provide access to iterator itself
        for (; i != i_end; ++i)
        {
            switch (std::error_code ec; i->status(ec).type())
            {
                case fs::file_type::regular:
                    if (const auto earlier_time = std::chrono::file_clock::now() - 2h;  // fs::file_time_type::clock::now() std::chrono::file_clock::now()
                        i->last_write_time() <= earlier_time)
                        std::cout << "OLD FILE: ";
                    else
                        std::cout << "file: ";
                    break;
            
                case fs::file_type::directory:
                    std::cout << "folder: ";
                    break;

                default:
                    i.disable_recursion_pending(); // i.e., member function of iterator
                    break;
            }
            std::cout << i->path().generic_string() << '\n';
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
