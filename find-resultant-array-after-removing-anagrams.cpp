#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> removeAnagrams(std::vector<std::string> &words) {
    auto areAnagrams = [](std::string &s1, std::string &s2) -> bool {
      if (s1.size() != s2.size()) {
        return false;
      }

      int freq[26] = {};
      for (int i = 0; i < s1.size(); ++i) {
        ++freq[s1[i] - 'a'];
        --freq[s2[i] - 'a'];
      }

      for (int &f : freq) {
        if (f != 0) {
          return false;
        }
      }

      return true;
    };

    std::vector<std::string> res;

    res.push_back(words[0]);
    for (int i = 1; i < words.size(); ++i) {
      if (!areAnagrams(res.back(), words[i])) {
        res.push_back(words[i]);
      }
    }

    return res;
  }
};
