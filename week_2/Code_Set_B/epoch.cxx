#include <chrono>
#include <ctime>
#include <iostream>
#include <string_view>

template <typename T>
requires std::chrono::is_clock_v<T>
void output_epoch(std::string_view sv)
{
  std::cout << sv << ' ' 
    << std::chrono::clock_cast<std::chrono::utc_clock>(typename T::time_point{}) << '\n';
}

int main()
{
  output_epoch<std::chrono::system_clock>("system clock");
  output_epoch<std::chrono::gps_clock>("GPS clock");
  output_epoch<std::chrono::tai_clock>("TAI clock");
  output_epoch<std::chrono::file_clock>("file clock");
}
