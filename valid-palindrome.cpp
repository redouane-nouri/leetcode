#include <algorithm>
#include <cctype>
#include <string>
class Solution {
public:
  bool isPalindrome(std::string s) {

    s.erase(std::remove_if(s.begin(), s.end(),
                           [](char c) { return !std::isalnum(c); }),
            s.end());
    std::transform(s.begin(), s.end(), s.begin(),
                   [](char c) { return std::tolower(c); });

    if (s.empty())
      return true;

    std::size_t l = 0, r = s.size() - 1;

    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }

    return true;
  }
};
