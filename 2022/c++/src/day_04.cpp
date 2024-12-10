#include "utils.h"

namespace day_04
{

auto create_sections(std::string const& range) -> std::vector<u64>
{
  u64 start = stoul(range.substr(0, range.find('-')));
  u64 end = stoul(range.substr(range.find('-') + 1));
  std::vector<u64> sections(end - start + 1);
  std::iota(sections.begin(), sections.end(), start);
  return sections;
}

Solution<u64> solve(std::string const& file_name)
{
  u64 number_of_pairs_that_fully_overlap{0};
  u64 number_of_pairs_that_overlap{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      auto [range1, range2] = aoc::utils::split_line(text, ",");

      auto sections1 = create_sections(range1);
      auto sections2 = create_sections(range2);

      if (std::includes(sections1.begin(), sections1.end(), sections2.begin(), sections2.end()) ||
          std::includes(sections2.begin(), sections2.end(), sections1.begin(), sections1.end())) {
        ++number_of_pairs_that_fully_overlap;
      }

      vector<u64> difference;
      std::set_intersection(sections1.begin(), sections1.end(), sections2.begin(), sections2.end(), std::back_inserter(difference));
      if (!difference.empty()) {
        ++number_of_pairs_that_overlap;
      }
    }
  }

  return {number_of_pairs_that_fully_overlap, number_of_pairs_that_overlap};
}

} // namespace day_04
