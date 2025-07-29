#include <algorithm>
#include <string>
#include <utility>

class Solution {
public:
  std::string addStrings(std::string num1, std::string num2) {
    int carry = 0, num1Sz = num1.size(), num2Sz = num2.size(), i = num1Sz - 1,
        j = num2Sz - 1;
    std::string res;

    while (i >= 0 || j >= 0 || carry) {
      int sum = (i >= 0 ? num1[i--] - '0' : 0) +
                (j >= 0 ? num2[j--] - '0' : 0) + carry;
      res.push_back((sum % 10) + '0');
      carry = sum / 10;
    }

    std::reverse(res.begin(), res.end());
    return res;
  }
};
