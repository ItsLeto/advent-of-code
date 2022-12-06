#include "days.h"
#include "utils.h"
int main(int argc, char const* argv[])
{
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());

  std::cout << argv[0] << std::endl;
  {
    auto [part1, part2] = day_01::solve("inputs/1.in");
    std::cout << "Day 01" << std::endl;
    std::cout << "  Part1: " << part1 << std::endl;
    std::cout << "  Part2: " << part2 << std::endl;
  }

  {
    auto [part1, part2] = day_02::solve("inputs/2.in");
    std::cout << "Day 02" << std::endl;
    std::cout << "  Part1: " << part1 << std::endl;
    std::cout << "  Part2: " << part2 << std::endl;
  }

  {
    auto [part1, part2] = day_03::solve("inputs/3.in");
    std::cout << "Day 03" << std::endl;
    std::cout << "  Part1: " << part1 << std::endl;
    std::cout << "  Part2: " << part2 << std::endl;
  }

  {
    auto [part1, part2] = day_04::solve("inputs/4.in");
    std::cout << "Day 04" << std::endl;
    std::cout << "  Part1: " << part1 << std::endl;
    std::cout << "  Part2: " << part2 << std::endl;
  }

  {
    auto [part1, part2] = day_05::solve("inputs/5.in");
    std::cout << "Day 05" << std::endl;
    std::cout << "  Part1: " << part1 << std::endl;
    std::cout << "  Part2: " << part2 << std::endl;
  }

  {
    auto [part1, part2] = day_06::solve("inputs/6.in");
    std::cout << "Day 06" << std::endl;
    std::cout << "  Part1: " << part1 << std::endl;
    std::cout << "  Part2: " << part2 << std::endl;
  }

  return 0;
}
