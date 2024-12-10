#include "utils.h"

namespace day_07
{

struct File
{
  File(string name, u64 size) : name(name), size(size){};
  string name;
  u64 size;
};

struct Directory
{
  string name;
  shared_ptr<Directory> parent;
  unordered_map<string, shared_ptr<Directory>> subdirs;
  vector<File> files;

  bool has_dir(string name)
  {
    return subdirs.find(name) != subdirs.end();
  };

  bool is_empty()
  {
    return subdirs.empty() && files.empty();
  };

  string repr(string indentation = "")
  {
    string repr = indentation + "- " + name + " (dir)\n";

    for (auto const& dir : subdirs) {
      repr += dir.second->repr(indentation + "....");
    }

    for (auto const& f : files) {
      repr += indentation + indentation + "- " + f.name + " (file, size=" + to_string(f.size) + ")\n";
    }

    if (files.empty()) {
      repr += "\n";
    }
    return repr;
  }

  u64 get_size()
  {
    u64 size = 0;
    size += accumulate(all(files), 0, [](u64 sum, auto& file) { return sum + file.size; });

    for (auto const& dir : subdirs) {
      size += dir.second->get_size();
    }

    return size;
  }

  vector<u64> get_sizes_of_all_subdirs()
  {
    vector<u64> sizes;
    sizes.push_back(get_size());
    for (auto const& dir : subdirs) {
      auto v = dir.second->get_sizes_of_all_subdirs();
      sizes.insert(sizes.end(), v.begin(), v.end());
    }
    return sizes;
  }
};

Solution<u64> solve(std::string const& file_name)
{
  u64 part1{0};
  u64 part2{0};

  std::shared_ptr<Directory> root = std::make_shared<Directory>();
  root->name = "/";

  std::shared_ptr<Directory> curr_dir = root;

  std::fstream in(file_name);
  std::string text;
  std::getline(in, text); // skip first line "$ cd /"
  while (std::getline(in, text)) {
    if (text.empty()) {
      continue;
    }

    if (text[0] == '$') {
      if (text == "$ cd ..") {
        if (curr_dir->parent) {
          curr_dir = curr_dir->parent;
        }
      }
      else if (text.find("cd") != string::npos) {
        std::string name = text.substr(5);
        if (curr_dir->has_dir(name)) {
          // Directory exists already
          curr_dir = curr_dir->subdirs[name];
        }
        else {
          // New Directory
          auto new_dir = make_shared<Directory>();
          new_dir->name = name;
          new_dir->parent = curr_dir;
          curr_dir->subdirs.insert({name, new_dir});
          curr_dir = new_dir;
        }
      }
    }
    else if (text.compare(0, 3, "dir") == 0) {
    }
    else {
      auto [size, name] = aoc::utils::split_line(text, " ");
      u64 s;
      sscanf(size.c_str(), "%lu", &s);
      curr_dir->files.emplace_back(name, s);
    }
  }

  // std::cout << root->repr();

  // Part 1
  auto dir_sizes = root->get_sizes_of_all_subdirs();
  part1 = accumulate(all(dir_sizes), 0ULL, [](u64 sum, u64 size) {
    if (size > 100'000) {
      return sum;
    }
    return sum + size;
  });

  // Part 2
  auto total = root->get_size();
  auto space_needed = 30'000'000 - (70'000'000 - total);

  dir_sizes.erase(std::remove_if(all(dir_sizes), [&](u64 size) { return size < space_needed; }), dir_sizes.end());

  part2 = *min_element(all(dir_sizes));

  return {part1, part2};
}

} // namespace day_07
