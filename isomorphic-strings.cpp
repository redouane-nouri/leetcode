#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }

    const std::size_t sz = s.size();

    std::unordered_map<char, char> sToT;
    std::unordered_set<char> mapped;

    for (std::size_t i = 0; i < sz; ++i) {
      if (sToT.count(s[i])) {
        if (sToT[s[i]] != t[i]) {
          return false;
        }
      } else {
        if (mapped.count(t[i])) {
          return false;
        }

        sToT[s[i]] = t[i];
        mapped.insert(t[i]);
      }
    }

    return true;
  }
};
