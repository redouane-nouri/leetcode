#include <vector>

class Solution {
public:
  int sumFourDivisors(std::vector<int> &nums) {
    int sum = 0;

    for (const int &num : nums) {
      int d1 = 0, d2 = 0;

      for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
          if (d1 || i == num / i) {
            d1 = 0;
            break;
          }

          d1 = i;
          d2 = num / i;
        }
      }

      if (d1 != 0)
        sum += 1 + d1 + d2 + num;
    }

    return sum;
  }
};
