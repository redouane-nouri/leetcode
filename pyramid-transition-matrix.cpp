#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  std::unordered_map<std::string, std::vector<char>> allowedMap;
  std::unordered_set<std::string> memo;

  bool build(const std::string &base, std::string &top) {
    if (top.size() == base.size() - 1)
      return canBuild(top);

    std::string key = base.substr(top.size(), 2);

    if (!allowedMap.count(key))
      return false;

    for (char c : allowedMap[key]) {
      top.push_back(c);

      if (build(base, top))
        return true;

      top.pop_back();
    }

    return false;
  }

  bool canBuild(std::string &base) {
    if (base.size() == 1)
      return true;

    if (memo.count(base))
      return false;

    std::string top;
    top.reserve(base.size() - 1);

    if (build(base, top))
      return true;

    memo.insert(base);
    return false;
  }

public:
  bool pyramidTransition(std::string bottom,
                         std::vector<std::string> &allowed) {
    for (const auto &s : allowed)
      allowedMap[s.substr(0, 2)].push_back(s[2]);

    return canBuild(bottom);
  }
};
