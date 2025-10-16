#include <vector>

class Solution {
public:
  int findSmallestInteger(std::vector<int> &nums, int value) {
    std::vector<int> freq(value, 0);

    for (int &num : nums) {
      ++freq[((num % value) + value) % value];
    }

    int mex = 0;

    while (true) {
      int r = mex % value;

      if (freq[r] == 0) {
        return mex;
      }

      --freq[r];
      ++mex;
    }
  }
};
