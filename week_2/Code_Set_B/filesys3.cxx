#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
  try
  {
    // range-based for loop...
    for (const auto& entry : fs::directory_iterator {
            (argc > 1 ? argv[1] : "/var/run"),
            fs::directory_options::skip_permission_denied
        })
    {
        std::error_code ec; // used to avoid throwing an exception if there is some type of error
        switch (entry.status(ec).type())
        {
            case fs::file_type::none:
                std::cout << "none: ";
                break;

            case fs::file_type::not_found:
                std::cout << "not found: ";
                break;

            case fs::file_type::regular:
                std::cout << "file: ";
                break;

            case fs::file_type::directory:
                std::cout << "directory: ";
                break;

            case fs::file_type::symlink:
                std::cout << "symlink: ";
                break;

            case fs::file_type::block:
            case fs::file_type::character:
            case fs::file_type::fifo:
            case fs::file_type::socket:
                std::cout << "system: ";
                break;

            default:
                std::cout << "other: ";
                break;
        }
        // std::cout << entry.path().generic_string() << '\n';
        std::cout << entry.path().filename() << '\n';
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
