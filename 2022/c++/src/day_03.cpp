#include "utils.h"

namespace day_03
{

auto get_prio(char c) -> int
{
  if (c <= 'Z' && c >= 'A') {
    return ((int)c - 'A') + 27;
  }
  return ((int)c - 'a') + 1;
}

u64 part1(std::string const& file_name)
{
  u64 total_sum{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      std::string s1 = text.substr(0, text.size() / 2);
      std::string s2 = text.substr(text.size() / 2, text.size());

      std::set<int> c1{};
      std::set<int> c2{};

      std::for_each(s1.begin(), s1.end(), [&](char c) -> void { c1.insert(get_prio(c)); });
      std::for_each(s2.begin(), s2.end(), [&](char c) -> void { c2.insert(get_prio(c)); });
      std::vector<int> v;
      set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(), std::back_inserter(v));
      auto sum = accumulate(v.begin(), v.end(), 0);
      total_sum += sum;
    }
  }
  return total_sum;
}

u64 part2(std::string const& file_name)
{
  u64 total_sum{0};
  std::vector<std::set<int>> bags;

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      std::set<int> items{};
      std::for_each(text.begin(), text.end(), [&](char c) -> void { items.insert(get_prio(c)); });
      bags.push_back(items);
    }
  }
  for (size_t i = 0; i < bags.size(); i += 3) {
    std::vector<int> common;
    std::vector<int> v;
    set_intersection(bags[i].begin(), bags[i].end(), bags[i + 1].begin(), bags[i + 1].end(), std::back_inserter(common));
    set_intersection(bags[i + 2].begin(), bags[i + 2].end(), common.begin(), common.end(), std::back_inserter(v));
    assert(v.size() == 1);
    total_sum += v.at(0);
  }
  return total_sum;
}

Solution<u64> solve(std::string const& file_name)
{
  return {part1(file_name), part2(file_name)};
}

} // namespace day_03
