#include <algorithm>
#include <vector>

class Solution {
public:
  long long maxProfit(std::vector<int> &prices, std::vector<int> &strategy,
                      int k) {
    const int N = prices.size();
    std::vector<long long> preSum(N + 1, 0), preSumStrat(N + 1, 0);

    for (int i = 0; i < N; ++i) {
      preSum[i + 1] = preSum[i] + prices[i];
      preSumStrat[i + 1] = preSumStrat[i] + (prices[i] * strategy[i]);
    }

    long long ans = preSumStrat[N];
    int start = 0, half = k >> 1, end = k;

    while (end <= N) {
      ans = std::max(ans, (preSumStrat[start] - preSumStrat[0]) +
                              (preSum[end] - preSum[half]) +
                              (preSumStrat[N] - preSumStrat[end]));
      ++start;
      ++half;
      ++end;
    }

    return ans;
  }
};
