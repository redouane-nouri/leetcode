#include <algorithm>
#include <string>

class Solution {
public:
  std::string multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    const int n = num1.size(), m = num2.size();
    std::string result(n + m, '0');

    for (int i = n - 1; i >= 0; --i) {
      int carry = 0;

      for (int j = m - 1; j >= 0; --j) {
        carry += result[i + j + 1] - '0';
        int mul = (num1[i] - '0') * (num2[j] - '0') + carry;

        carry = mul / 10;
        result[i + j + 1] = mul % 10 + '0';
      }

      if (carry)
        result[i] = carry + '0';
    }

    return result.substr(result.find_first_not_of('0'));
  }
};
