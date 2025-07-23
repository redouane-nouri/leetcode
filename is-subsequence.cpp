#include <string>

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    int i = 0, sSz = s.size(), j = 0, tSz = t.size();

    while (i < sSz && j < tSz) {
      if (s[i] == t[j])
        ++i;

      ++j;
    }

    return i == sSz;
  }
};
