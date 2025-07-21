#include <string>

class Solution {
public:
  bool isNumber(std::string s) {
    bool isNumeric = false, dotFound = false, expFound = false;
    int sz = s.size(), i = 0;

    if (s[i] == '-' || s[i] == '+')
      ++i;

    while (i < sz) {
      if (s[i] >= '0' && s[i] <= '9') {
        isNumeric = true;
      } else if (s[i] == '.') {
        if (dotFound || expFound)
          return false;

        dotFound = true;
      } else if (s[i] == 'e' || s[i] == 'E') {
        if (expFound || !isNumeric)
          return false;

        expFound = true;
        isNumeric = false;

        if (i + 1 < sz && (s[i + 1] == '-' || s[i + 1] == '+'))
          ++i;
      } else {
        return false;
      }

      ++i;
    }

    return isNumeric;
  }
};
