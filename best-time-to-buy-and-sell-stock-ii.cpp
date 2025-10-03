#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int n = prices.size(), res = 0;

    for (int i = 1; i < n; ++i)
      if (prices[i - 1] < prices[i])
        res += prices[i] - prices[i - 1];

    return res;
  }
};
