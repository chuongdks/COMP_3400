#include <chrono>
#include <iostream>

int main()
{
  [[maybe_unused]] auto tp1 = std::chrono::file_clock::now();
  [[maybe_unused]] auto tp2 = std::chrono::steady_clock::now();
  [[maybe_unused]] auto tp3 = std::chrono::system_clock::now();
}
