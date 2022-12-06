#include "utils.h"

namespace day_06
{

u64 part1(std::string const& file_name)
{
  u64 total_sum{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
        cout << endl;
        // constexpr int MARKER_LENGTH = 4;
        constexpr int MARKER_LENGTH = 14;
    for (int i = 0; i<text.size()-MARKER_LENGTH; i++) {
      set<char> marker(text.begin()+i,  text.begin()+i+MARKER_LENGTH);
        cout << marker.size() << " ";

      if (marker.size() == MARKER_LENGTH) {
        total_sum = i + MARKER_LENGTH;
          cout << imie(total_sum) << endl;

          break;
        }


      }
        cout << endl;
    }
  }

  return total_sum;
}

u64 part2(std::string const& file_name)
{
  u64 total_sum{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
    }
    else {
    }
  }

  return total_sum;
}

Solution solve(std::string const& file_name)
{
  return {part1(file_name), part2(file_name)};
}

} // namespace day_06
