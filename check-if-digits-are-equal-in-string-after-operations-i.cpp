#include <string>

class Solution {
public:
  bool hasSameDigits(std::string s) {
    int n = s.size();
    while (n > 2) {
      for (int i = 0; i < n - 1; ++i) {
        int d = s[i] + s[i + 1] - ('0' << 1);
        if (d >= 10) {
          d -= 10;
        }
        s[i] = d + '0';
      }

      --n;
    }

    return s[0] == s[1];
  }
};
