#include <vector>
class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    for (std::vector<int>::reverse_iterator it = digits.rbegin();
         it != digits.rend(); it++) {
      if (*it < 9) {
        *it = *it + 1;
        return digits;
      }

      *it = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
  }
};
