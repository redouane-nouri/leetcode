#include <string>

class Solution {
public:
  std::string countAndSay(int n) {
    std::string s = "1";

    while (n > 1) {
      int sz = s.size();
      std::string t;
      t.reserve(sz * 2);
      int i = 0;

      while (i < sz) {
        int j = 1;
        while (i < sz - 1 && s[i] == s[i + 1]) {
          ++i;
          ++j;
        }

        t += std::to_string(j) + s[i++];
      }

      s = t;
      --n;
    }

    return s;
  }
};
