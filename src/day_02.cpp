#include "template.hpp"

namespace day_02
{

u64 part1(std::string const& file_name)
{
  u64 total_sum{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
    }
  }

  return total_sum;
}

u64 part2(std::string const& file_name)
{
  u64 total_sum{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
    }
  }

  return total_sum;
}

Solution solve(std::string const& file_name)
{
  return {part1(file_name), part2(file_name)};
}

} // namespace day_02
