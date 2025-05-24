#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, std::size_t> charIndex;
    const std::size_t size = s.size();
    std::size_t l = 0, res = 0;

    for (std::size_t r = 0; r < size; ++r) {
      if (charIndex.count(s[r]) && charIndex[s[r]] >= l) {
        l = charIndex[s[r]] + 1;
      }

      charIndex[s[r]] = r;

      if (res < (r - l + 1)) {
        res = r - l + 1;
      }
    }

    return res;
  }
};
