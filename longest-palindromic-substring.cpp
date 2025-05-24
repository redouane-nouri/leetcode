#include <string>
class Solution {
public:
  std::string longestPalindrome(std::string s) {
    const std::size_t sz = s.size();
    std::size_t start = 0, length = 0;

    for (std::size_t i = 0; i < sz; ++i) {
      findPalindrome(s, sz, i, i, start, length);
      findPalindrome(s, sz, i, i + 1, start, length);
    }

    return s.substr(start, length);
  }

private:
  void findPalindrome(std::string &s, const std::size_t &sz, std::size_t l,
                      std::size_t r, std::size_t &start, std::size_t &length) {
    while (l < sz && r < sz && s[l] == s[r]) {
      --l;
      ++r;
    }

    if ((r - l - 1) > length) {
      start = l + 1;
      length = r - l - 1;
    }
  }
};
