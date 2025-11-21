#include <string>

class Solution {
public:
  int countPalindromicSubsequence(std::string s) {
    const int n = s.size();
    int charsUpperBound[26] = {0}, idx = n - 1, totalUniqueChars = 0;

    while (idx >= 0 && totalUniqueChars < 26) {
      if (charsUpperBound[s[idx] - 'a'] == 0) {
        charsUpperBound[s[idx] - 'a'] = idx;
        ++totalUniqueChars;
      }

      --idx;
    }

    bool omitChars[26] = {false};
    int i = 0, omitted = 0, res = 0;

    while (i < n - 2 && omitted < totalUniqueChars) {
      const int charIdx = s[i] - 'a';

      if (!omitChars[charIdx] && i + 1 < charsUpperBound[charIdx]) {
        omitChars[charIdx] = true;

        bool ignoreChars[26] = {false};
        int j = i + 1, ignored = 0;

        while (j < charsUpperBound[charIdx] && ignored < totalUniqueChars) {
          if (!ignoreChars[s[j] - 'a']) {
            ignoreChars[s[j] - 'a'] = true;
            ++res;
            ++ignored;
          }

          ++j;
        }
      }

      ++i;
    }

    return res;
  }
};
