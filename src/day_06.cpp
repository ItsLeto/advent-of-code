#include "utils.h"

namespace day_06
{

Solution solve(std::string const& file_name)
{
  u64 part1{0};
  u64 part2{0};

  std::fstream in(file_name);
  std::string text;
  while (std::getline(in, text)) {
    if (text.empty()) {
      continue;
    }

    constexpr int BEGIN_MSG_MARKER_LENGTH = 4;
    for (int i = 0; i < text.size() - BEGIN_MSG_MARKER_LENGTH; i++) {
      set<char> marker(text.begin() + i, text.begin() + i + BEGIN_MSG_MARKER_LENGTH);
      if (marker.size() == BEGIN_MSG_MARKER_LENGTH) {
        part1 = i + BEGIN_MSG_MARKER_LENGTH;
        break;
      }
    }

    constexpr int MARKER_LENGTH = 14;
    for (int i = 0; i < text.size() - MARKER_LENGTH; i++) {
      set<char> marker(text.begin() + i, text.begin() + i + MARKER_LENGTH);
      if (marker.size() == MARKER_LENGTH) {
        part2 = i + MARKER_LENGTH;
        break;
      }
    }
  }

  return {part1, part2};
}

} // namespace day_06
