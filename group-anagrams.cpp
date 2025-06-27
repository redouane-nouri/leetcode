#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

    for (std::string &s : strs) {
      std::string str = s;
      std::sort(str.begin(), str.end());
      anagramGroups[str].push_back(s);
    }

    std::vector<std::vector<std::string>> res;
    res.reserve(anagramGroups.size());

    for (auto &anagramGroup : anagramGroups) {
      res.push_back(std::move(anagramGroup.second));
    }

    return res;
  }
};
