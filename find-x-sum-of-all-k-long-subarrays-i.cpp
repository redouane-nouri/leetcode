#include <algorithm>
#include <array>
#include <vector>

class Solution {
  int xSum(std::vector<int> &nums, int start, int end, int x) {
    std::vector<std::array<int, 2>> freq(51);

    freq[0] = {0, 0};
    for (int i = 1; i <= 50; ++i) {
      freq[i] = {i, 0};
    }
    for (int i = start; i < end; ++i) {
      ++freq[nums[i]][1];
    }

    std::sort(freq.begin(), freq.end(),
              [](const std::array<int, 2> &a, const std::array<int, 2> &b) {
                if (a[1] == b[1]) {
                  return a[0] > b[0];
                }

                return a[1] > b[1];
              });

    int sum = 0;

    for (int i = 0; i < x; ++i) {
      sum += freq[i][0] * freq[i][1];
    }

    return sum;
  }

public:
  std::vector<int> findXSum(std::vector<int> &nums, int k, int x) {
    int n = nums.size();
    std::vector<int> res(n - k + 1);

    for (int i = 0; i <= n - k; ++i) {
      res[i] = xSum(nums, i, i + k, x);
    }

    return res;
  }
};
