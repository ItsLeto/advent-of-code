#include "utils.h"

namespace day_05
{

vector<char> split(string line)
{
  vector<char> p;
  for (int i = 0; i < line.size(); i += 4) {
    debug() << imie(i) << line.size();
    string c = line.substr(i, 3);
    debug() << "'" << c << "'";
    p.push_back(c[1]);
  }
  return p;
}

u64 part1(std::string const& file_name)
{
  u64 total_sum{0};

  struct Move
  {
    int a;
    int f;
    int t;
  };
  vector<Move> moves;
  vector<deque<char>> stacks(9);

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      if (text.find("[") != std::string::npos) {
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
        debug() << imie(a) << imie(f) << imie(t);
        moves.push_back({a, f - 1, t - 1});
      }
      else {
        cout << "ERROR" << endl;
      }
    }
  }

  // for (auto& s : stacks) {
  // debug() << s;

  for (auto move : moves) {
    cout << imie(move.a) << endl;
    cout << imie(move.f) << endl;
    cout << imie(move.t) << endl;
    cout << imie(stacks.size()) << endl;
    for (int i = 0; i < move.a; ++i) {
      stacks[move.t].push_front(stacks[move.f].front());
      stacks[move.f].pop_front();
    }
  }

  string r = "";
  for (auto s : stacks) {
    if (s.empty()) continue;
    cout << imie(s.size()) << endl;
    r += s.front();
  }
  cout << imie(r);

  return total_sum;
}

u64 part2(std::string const& file_name)
{
  u64 total_sum{0};


  struct Move
  {
    int a;
    int f;
    int t;
  };
  vector<Move> moves;
  vector<deque<char>> stacks(9);

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      if (text.find("[") != std::string::npos) {
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
        debug() << imie(a) << imie(f) << imie(t);
        moves.push_back({a, f - 1, t - 1});
      }
      else {
        cout << "ERROR" << endl;
      }
    }
  }

  // for (auto& s : stacks) {
  // debug() << s;

  for (auto move : moves) {
    deque<char> crane;
    for (int i = 0; i < move.a; ++i) {
      crane.push_back(stacks[move.f].front());
      stacks[move.f].pop_front();
    }
    for (int i = 0; i < move.a; ++i) {
      stacks[move.t].push_front(crane.back());
      crane.pop_back();
    }

  }

  string r = "";
  for (auto s : stacks) {
    if (s.empty()) continue;
    cout << imie(s.size()) << endl;
    r += s.front();
  }
  cout << imie(r);

  return total_sum;
}

Solution solve(std::string const& file_name)
{
  return {part1(file_name), part2(file_name)};
}

} // namespace day_05
