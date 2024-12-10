#include "utils.h"

namespace day_09
{

Solution<u64> solve(std::string const& file_name)
{
  u64 part1{0};
  u64 part2{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
      continue;
    }
  }

  return {part1, part2};
}

} // namespace day_09
