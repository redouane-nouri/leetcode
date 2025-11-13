#include <string>

class Solution {
public:
  int maxOperations(std::string s) {
    const int n = s.size();
    int oneIndex = n;

    while (oneIndex > 0 && s[oneIndex - 1] == '1') {
      --oneIndex;
    }

    int i = 0, res = 0, curr = 0;
    bool zeroFound = false;

    while (i < oneIndex) {
      if (s[i] == '1') {
        zeroFound = false;
        ++curr;
      } else if (!zeroFound) {
        zeroFound = true;
        res += curr;
      }

      ++i;
    }

    return res;
  }
};
