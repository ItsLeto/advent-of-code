#include "utils.h"

namespace day_05
{

vector<char> split(std::string const& line)
{
  std::vector<char> p;
  for (int i = 0; i < line.size(); i += 4) {
    // Middle of the crate holds the letter this would be index 1 for the first and 4 more for each subsequent crate
    // [A] [B] [C]
    // [A]  _  [C]
    p.push_back(line[i + 1]);
  }
  return p;
}

struct Move
{
  u64 amount;
  u64 id_from;
  u64 id_to;
};

Solution<std::string> solve(std::string const& file_name)
{
  std::vector<Move> moves;
  std::vector<std::deque<char>> stacks(9);

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
      continue;
    }

    if (text.find('[') != std::string::npos) {
      // split in cols
      auto crates = split(text);
      for (size_t idx{0}; idx < crates.size(); ++idx) {
        if (crates[idx] != ' ') {
          stacks[idx].push_back(crates[idx]);
        }
      }
    }
    else if (text[0] == 'm') {
      u64 amount;
      u64 id_from;
      u64 id_to;
      sscanf(text.c_str(), "move %lu from %lu to %lu", &amount, &id_from, &id_to);
      moves.push_back({amount, id_from - 1, id_to - 1});
    }
  }

  // Part 1
  auto stacks1 = stacks;
  for (auto move : moves) {
    for (int i = 0; i < move.amount; ++i) {
      stacks1[move.id_to].push_front(stacks1[move.id_from].front());
      stacks1[move.id_from].pop_front();
    }
  }

  std::string part1;
  for (auto s : stacks1) {
    if (!s.empty()) {
      part1 += s.front();
    }
  }

  // Part 2
  auto stacks2 = stacks;
  for (auto move : moves) {
    std::deque<char> crane;
    for (int i = 0; i < move.amount; ++i) {
      crane.push_back(stacks2[move.id_from].front());
      stacks2[move.id_from].pop_front();
    }
    for (int i = 0; i < move.amount; ++i) {
      stacks2[move.id_to].push_front(crane.back());
      crane.pop_back();
    }
  }

  std::string part2;
  for (auto s : stacks2) {
    if (!s.empty()) {
      part2 += s.front();
    }
  }

  return {part1, part2};
}

} // namespace day_05
