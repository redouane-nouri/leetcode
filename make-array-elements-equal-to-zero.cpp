#include <numeric>
#include <vector>

class Solution {
public:
  int countValidSelections(std::vector<int> &nums) {
    int n = nums.size(), res = 0, leftSum = 0,
        rightSum = std::accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        switch (rightSum - leftSum) {
        case 0:
        case 1:
          ++res;
        }

        switch (leftSum - rightSum) {
        case 0:
        case 1:
          ++res;
        }
      } else {
        leftSum += nums[i];
        rightSum -= nums[i];
      }
    }

    return res;
  }
};
