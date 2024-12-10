#include "utils.h"

namespace day_10
{

constexpr auto ADDX = "addx";
constexpr auto NOOP = "noop";

auto solve(std::string const& file_name) -> Solution<string>
{
  u64 part1{0};
  u64 part2{0};

  u64 pc{1};
  i64 eax{1};

  map<u64, i64> signal_strength;
  auto store_signal_strength = [&]() {
    if (pc % 40 == 20) {
      signal_strength[pc] = pc * eax;
    }
  };

  vector<vector<char>> crt;
  for (int i{0}; i < 6; ++i) {
    crt.push_back(vector<char>(40, '.'));
  }

  auto draw_pixel = [&]() {
    u64 crt_row_idx = std::clamp((pc - 2) / 40, 0UL, 5UL);
    u64 sprite_pos = std::clamp(eax - 1, 0L, 39L);
    u64 crt_pix_pos = (pc - 2) % 40;
    if (crt_pix_pos == sprite_pos - 1 || crt_pix_pos == sprite_pos + 1 || crt_pix_pos == sprite_pos) {
      crt[crt_row_idx][crt_pix_pos] = '#';
    }
  };

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
      continue;
    }
    stringstream stream;
    stream << text;

    string op;
    i64 arg{0};

    stream >> op;
    stream >> arg;

    if (op == NOOP || op == ADDX) {
      ++pc;
    }
    store_signal_strength();
    draw_pixel();

    if (op == ADDX) {
      ++pc;
      eax += arg;
    }
    store_signal_strength();
    draw_pixel();
  }

  part1 = accumulate(all(signal_strength), 0, [](u64 sum, auto strength) { return sum + strength.second; });

  stringstream screen;
  screen << '\n';
  for (auto const& row : crt) {
    screen << "\t";
    for (auto const& p : row) {
      screen << p;
    }
    screen << '\n';
  }

  return {std::to_string(part1), screen.str()};
}

} // namespace day_10
