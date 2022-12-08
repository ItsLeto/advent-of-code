#include "utils.h"

namespace day_08
{

Solution<u64> solve(std::string const& file_name)
{
  u64 part1{0};
  u64 part2 = 0;

  vector<vector<char>> grid;

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
      vector<char> row(text.begin(), text.end());
      grid.emplace_back(std::move(row));
    }
  }

  auto hight = grid.size();
  auto width = grid[0].size();

  part1 += (2 * hight + 2 * (width - 2));

  for (u64 y{1}; y < grid.size() - 1; ++y) {
    for (u64 x{1}; x < grid[0].size() - 1; ++x) {
      auto& tree = grid[y][x];

      bool visible_to_the_left = true;
      bool visible_to_the_right = true;
      bool visible_to_the_top = true;
      bool visible_to_the_bottom = true;
      u64 left_view{0}, right_view{0}, up_view{0}, down_view{0};

      for (u64 xr{x + 1}; xr < grid[0].size(); ++xr) {
        ++right_view;
        if (grid[y][xr] >= tree) {
          visible_to_the_right = false;
          break;
        }
      }
      for (i64 xl{x - 1}; xl >= 0; --xl) {
        ++left_view;
        if (grid[y][xl] >= tree) {
          visible_to_the_left = false;
          break;
        }
      }
      for (u64 yb{y + 1}; yb < grid.size(); ++yb) {
        ++down_view;
        if (grid[yb][x] >= tree) {
          visible_to_the_bottom = false;
          break;
        }
      }
      for (i64 yt{y - 1}; yt >= 0; --yt) {
        ++up_view;
        if (grid[yt][x] >= tree) {
          visible_to_the_top = false;
          break;
        }
      }

      if (visible_to_the_left || visible_to_the_right || visible_to_the_top || visible_to_the_bottom) {
        ++part1;
      }

      u64 science_score = right_view * left_view * up_view * down_view;
      if (science_score > part2) {
        part2 = science_score;
      }
    }
  }

  return {part1, part2};
}

} // namespace day_08
