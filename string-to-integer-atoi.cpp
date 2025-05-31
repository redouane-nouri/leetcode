#include <climits>
#include <string>

#define POSITIVE 1
#define NEGATIVE -1

class Solution {
public:
  int myAtoi(std::string s) {
    const std::size_t size = s.size();
    std::size_t i = 0;
    int res = 0, digit, sign = POSITIVE;

    while (i < size && s[i] == ' ') {
      ++i;
    }

    if (i < size && (s[i] == '-' || s[i] == '+')) {
      sign = (s[i] == '-') ? NEGATIVE : POSITIVE;
      ++i;
    }

    while (i < size && std::isdigit(s[i])) {
      digit = s[i++] - '0';

      if (sign == POSITIVE) {
        if (res > (INT_MAX - digit) / 10)
          return INT_MAX;

        res = (res * 10) + digit;
      } else {
        if (res < (INT_MIN + digit) / 10)
          return INT_MIN;

        res = (res * 10) - digit;
      }
    }

    return res;
  }
};
