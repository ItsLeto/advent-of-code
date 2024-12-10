#include "utils.h"

std::pair<std::string, std::string> aoc::utils::split_line(std::string const& str, const char* delimiter)
{
  auto split_idx = str.find(delimiter);
  std::string p1 = str.substr(0, split_idx);
  std::string p2 = str.substr(split_idx + 1);
  return {p1, p2};
}
