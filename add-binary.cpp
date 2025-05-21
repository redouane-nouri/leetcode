#include <algorithm>
#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string::reverse_iterator a_it = a.rbegin(), b_it = b.rbegin(),
                                  a_end = a.rend(), b_end = b.rend();
    std::string result = "";
    unsigned int carry = 0, sum = 0;

    while (a_it != a_end || b_it != b_end) {
      sum = carry;

      if (a_it != a_end) {
        sum += *a_it - '0';
        ++a_it;
      }

      if (b_it != b_end) {
        sum += *b_it - '0';
        ++b_it;
      }

      carry = sum / 2;
      result.push_back((sum % 2) + '0');
    }

    if (carry) {
      result.push_back('1');
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};
