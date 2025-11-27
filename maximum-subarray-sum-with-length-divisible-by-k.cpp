#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  long long maxSubarraySum(std::vector<int> &nums, int k) {
    const int n = nums.size();
    std::vector<long long> preSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      preSum[i + 1] = preSum[i] + nums[i];
    }

    long long res = LLONG_MIN;

    for (int start = 0; start < k; ++start) {
      long long minSum = preSum[start];

      for (int end = start + k; end <= n; end += k) {
        res = std::max(res, preSum[end] - minSum);
        minSum = std::min(minSum, preSum[end]);
      }
    }

    return res;
  }
};
