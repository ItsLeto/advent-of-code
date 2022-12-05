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
  int a;
  int f;
  int t;
};

std::string part1(std::string const& file_name)
{
  std::vector<Move> moves;
  std::vector<std::deque<char>> stacks(9);

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      if (text.find('[') != std::string::npos) {
        // split in cols
        auto creats = split(text);
        for (int idx{0}; idx < creats.size(); ++idx) {
          if (creats[idx] != ' ') {
            stacks[idx].push_back(creats[idx]);
          }
        }
      }
      else if (text[0] == 'm') {
        int a, f, t;
        sscanf(text.c_str(), "move %d from %d to %d", &a, &f, &t);
        moves.push_back({a, f - 1, t - 1});
      }
    }
  }

  for (auto move : moves) {
    for (int i = 0; i < move.a; ++i) {
      stacks[move.t].push_front(stacks[move.f].front());
      stacks[move.f].pop_front();
    }
  }

  std::string result;
  for (auto s : stacks) {
    if (!s.empty()) {
      result += s.front();
    }
  }
  return result;
}

std::string part2(std::string const& file_name)
{
  std::vector<Move> moves;
  std::vector<std::deque<char>> stacks(9);

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      if (text.find('[') != std::string::npos) {
        // split in cols
        auto creats = split(text);
        for (int idx{0}; idx < creats.size(); ++idx) {
          if (creats[idx] != ' ') {
            stacks[idx].push_back(creats[idx]);
          }
        }
      }
      else if (text[0] == 'm') {
        int a, f, t;
        sscanf(text.c_str(), "move %d from %d to %d", &a, &f, &t);
        moves.push_back({a, f - 1, t - 1});
      }
    }
  }

  for (auto move : moves) {
    std::deque<char> crane;
    for (int i = 0; i < move.a; ++i) {
      crane.push_back(stacks[move.f].front());
      stacks[move.f].pop_front();
    }
    for (int i = 0; i < move.a; ++i) {
      stacks[move.t].push_front(crane.back());
      crane.pop_back();
    }
  }

  std::string result;
  for (auto s : stacks) {
    if (!s.empty()) {
      result += s.front();
    }
  }
  return result;
}

std::pair<std::string, std::string> solve(std::string const& file_name)
{
  return {part1(file_name), part2(file_name)};
}

} // namespace day_05
