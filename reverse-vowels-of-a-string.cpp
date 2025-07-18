#include <string>
#include <utility>

class Solution {
public:
  std::string reverseVowels(std::string s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
      while (!isVowel(s[l]) && l++ < r) {
      }

      while (!isVowel(s[r]) && r-- > l) {
      }

      if (l < r)
        std::swap(s[l++], s[r--]);
    }

    return s;
  }

private:
  bool isVowel(char c) {
    switch (c | 0x20) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;

    default:
      return false;
    }
  }
};
