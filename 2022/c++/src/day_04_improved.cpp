#include "utils.h"

namespace day_04
{

auto create_interval(std::string const& range) -> std::pair<u64, u64>
{
  u64 start = stoul(range.substr(0, range.find('-')));
  u64 end = stoul(range.substr(range.find('-') + 1));
  return {start, end};
}

u64 part1(std::string const& file_name)
{
  u64 number_of_pairs_that_fully_overlap{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      auto [range1, range2] = aoc::utils::split_line(text, ",");

      auto [s1, e1] = create_interval(range1);
      auto [s2, e2] = create_interval(range2);

      if ((s1 <= s2 && e2 <= e1) || (s2 <= s1 && e1 <= e2)) {
        ++number_of_pairs_that_fully_overlap;
      }
    }
  }

  return number_of_pairs_that_fully_overlap;
}

u64 part2(std::string const& file_name)
{
  u64 number_of_pairs_that_overlap{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      auto [range1, range2] = aoc::utils::split_line(text, ",");

      auto [s1, e1] = create_interval(range1);
      auto [s2, e2] = create_interval(range2);

      if (!(e2 < s1 || e1 < s2)) {
        ++number_of_pairs_that_overlap;
      }
    }
  }

  return number_of_pairs_that_overlap;
}

Solution<u64> solve(std::string const& file_name)
{
  return {part1(file_name), part2(file_name)};
}

} // namespace day_04
