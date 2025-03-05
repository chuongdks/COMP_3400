#include <chrono>
#include <iostream>

template <typename T>
requires std::chrono::is_clock_v<T>
auto resolution() { return static_cast<long double>(T::period::num) / T::period::den; }

int main()
{
  std::cout << resolution<std::chrono::system_clock>() << " seconds\n";
  std::cout << resolution<std::chrono::steady_clock>() << " seconds\n";
  std::cout << resolution<std::chrono::high_resolution_clock>() << " seconds\n";
  std::cout << resolution<std::chrono::file_clock>() << " seconds\n";
}
