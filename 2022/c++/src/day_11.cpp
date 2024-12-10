#include "utils.h"

namespace day_11
{

class Monkey
{
public:
  u64 id;
  deque<u64> worry_levels;
  char op;
  u64 op_factor;
  u64 test_factor;
  u64 true_monkey, false_monkey;
  u64 number_of_inspections{0};

  static Monkey from_string(std::vector<std::string> str)
  {
    Monkey m;
    sscanf(str[0].c_str(), "Monkey %lu", &m.id);

    stringstream levels;
    levels << str[1].substr(17);

    for (u64 i; levels >> i;) {
      m.worry_levels.push_back(i);
      if (levels.peek() == ',') {
        levels.ignore();
      }
    }

    if (str[2] == "  Operation: new = old * old") {
      m.op = '^';
    }
    else {
      sscanf(str[2].c_str(), "  Operation: new = old %c %lu", &m.op, &m.op_factor);
    }

    sscanf(str[3].c_str(), "  Test: divisible by %lu", &m.test_factor);
    sscanf(str[4].c_str(), "    If true: throw to monkey %lu", &m.true_monkey);
    sscanf(str[5].c_str(), "    If false: throw to monkey %lu", &m.false_monkey);

    return m;
  }

  deque<u64> inspect_items()
  {
    deque<u64> new_worry_levels;
    // debug() << imie(worry_levels);
    while (!worry_levels.empty()) {
      auto worry_level = worry_levels.front();
      worry_levels.pop_front();
      if (op == '+') {
        new_worry_levels.push_back(worry_level + op_factor);
      }
      else if (op == '^') {
        new_worry_levels.push_back(worry_level * worry_level);
      }
      else {
        new_worry_levels.push_back(worry_level * op_factor);
      }
      // debug() << imie(worry_level) << imie(op) << imie(new_worry_levels.back());
      if (new_worry_levels.back() < worry_level) {
        debug() << "Overflow!!!  " << imie(worry_level) << imie(op) << imie(new_worry_levels.back());
      }
      ++number_of_inspections;
    }

    // debug() << imie(new_worry_levels);
    return new_worry_levels;
  }

  std::pair<deque<u64>, deque<u64>> inspect_and_throw(bool part2 = false, u64 mod = 3)
  {
    auto new_worry_levels = inspect_items();
    deque<u64> throw_to_true_monkey;
    deque<u64> throw_to_false_monkey;
    for (auto&& wl : new_worry_levels) {
      u64 wl_constrained = (part2) ? (wl % mod) : (wl / 3);
      if (wl_constrained % test_factor == 0) {
        throw_to_true_monkey.push_back(wl_constrained);
      }
      else {
        throw_to_false_monkey.push_back(wl_constrained);
      }
    }
    // debug() << imie(true_monkey) << imie(throw_to_true_monkey) << imie(false_monkey) << imie(throw_to_false_monkey);

    return {throw_to_true_monkey, throw_to_false_monkey};
  }

  void catch_items(deque<u64> wls)
  {
    worry_levels.insert(worry_levels.end(), wls.begin(), wls.end());
  }
};

ostream& operator<<(ostream& output, const Monkey& m)
{
  output << "Monkey " << m.id << ": ";
  for (auto& wl : m.worry_levels) {
    output << wl << ", ";
  }
  return output;
}

auto solve(std::string const& file_name) -> Solution<u64>
{
  u64 part1{0};
  u64 part2{0};

  std::fstream in(file_name);
  std::string text;
  std::vector<std::string> monkey;
  std::vector<Monkey> monkeys;
  while (std::getline(in, text)) {
    if (text.empty()) {
      monkeys.push_back(Monkey::from_string(monkey));
      monkey.clear();
      continue;
    }
    monkey.push_back(text);
  }

  {
    auto monkeys1 = monkeys;
    for (u64 round_number{0}; round_number < 20; ++round_number) {
      for (auto& monkey : monkeys1) {
        auto thrown_items = monkey.inspect_and_throw();
        monkeys1[monkey.true_monkey].catch_items(thrown_items.first);
        monkeys1[monkey.false_monkey].catch_items(thrown_items.second);
      }
    }

    vector<u64> monkey_business;
    for (auto const& monkey : monkeys1) {
      monkey_business.push_back(monkey.number_of_inspections);
    }
    sort(all(monkey_business), std::greater<>());
    debug() << monkey_business;
    part1 = monkey_business[0] * monkey_business[1];
  }

  {
    auto monkeys2 = monkeys;
    for (u64 round_number{0}; round_number < 10000; ++round_number) {
      for (auto& monkey : monkeys2) {
        auto thrown_items = monkey.inspect_and_throw(true, (3 * 5 * 2 * 13 * 11 * 17 * 19 * 7));
        monkeys2[monkey.true_monkey].catch_items(thrown_items.first);
        monkeys2[monkey.false_monkey].catch_items(thrown_items.second);
      }
    }

    vector<u64> monkey_business;
    for (auto const& monkey : monkeys2) {
      monkey_business.push_back(monkey.number_of_inspections);
    }
    sort(all(monkey_business), std::greater<>());
    debug() << monkey_business;
    part2 = monkey_business[0] * monkey_business[1];
  }

  return {part1, part2};
}

} // namespace day_11
