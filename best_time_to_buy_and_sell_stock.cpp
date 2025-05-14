#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int min = prices[0], max_profit = 0;

    for (std::size_t i = 1; i < prices.size(); ++i) {
      if (min > prices[i]) {
        min = prices[i];
      } else {
        max_profit = std::max(max_profit, prices[i] - min);
      }
    }

    return max_profit;
  }
};
