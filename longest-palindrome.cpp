#include <string>

class Solution {
public:
  int longestPalindrome(std::string s) {
    int res = 0, freq[128] = {0};
    bool hasOdd = false;

    for (char c : s)
      ++freq[c];

    for (int i = 65; i < 123; ++i) {
      if (!hasOdd && freq[i] % 2 != 0) {
        hasOdd = true;
        ++res;
      }

      res += (freq[i] / 2) * 2;
    }

    return res;
  }
};
