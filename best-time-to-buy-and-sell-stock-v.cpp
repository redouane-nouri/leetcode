#include <algorithm>
#include <vector>

class Solution {
  std::vector<std::vector<std::vector<long long>>> memo;
  std::vector<int> *p;
  const int IDLE_STATE = 0, NORMAL_STATE = 1, SHORT_STATE = 2;

  long long dfs(int day, int transactionsLeft, int state) {
    if (transactionsLeft == 0)
      return 0;

    int &price = (*p)[day];

    if (day == 0)
      return state == IDLE_STATE ? 0 : (state == NORMAL_STATE ? -price : price);

    if (memo[day][transactionsLeft][state] != -1)
      return memo[day][transactionsLeft][state];

    long long maxProfit;

    if (state == IDLE_STATE) {
      maxProfit =
          std::max({dfs(day - 1, transactionsLeft, IDLE_STATE),
                    dfs(day - 1, transactionsLeft, NORMAL_STATE) + price,
                    dfs(day - 1, transactionsLeft, SHORT_STATE) - price});
    } else if (state == NORMAL_STATE) {
      maxProfit =
          std::max(dfs(day - 1, transactionsLeft - 1, IDLE_STATE) - price,
                   dfs(day - 1, transactionsLeft, NORMAL_STATE));
    } else {
      maxProfit =
          std::max(dfs(day - 1, transactionsLeft - 1, IDLE_STATE) + price,
                   dfs(day - 1, transactionsLeft, SHORT_STATE));
    }

    memo[day][transactionsLeft][state] = maxProfit;
    return maxProfit;
  }

public:
  long long maximumProfit(std::vector<int> &prices, int k) {
    p = &prices;
    memo.resize(prices.size(),
                std::vector(k + 1, std::vector<long long>(3, -1)));
    return dfs(prices.size() - 1, k, 0);
  }
};
