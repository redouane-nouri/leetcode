#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  long long maximumTotalDamage(std::vector<int> &power) {
    std::vector<std::pair<int, long long>> sumPower;
    int sumI = 0, i = 0, n = power.size();

    std::sort(power.begin(), power.end());

    while (i < n) {
      sumPower.push_back({power[i], power[i++]});

      while (i < n && power[i] == sumPower[sumI].first) {
        sumPower[sumI].second += power[i++];
      }

      ++sumI;
    }

    int m = sumPower.size();
    std::vector<long long> dp(m);
    long long mx = 0;

    for (int i = 0, j = 0; i < m; ++i) {
      while (sumPower[j].first < sumPower[i].first - 2) {
        mx = std::max(mx, dp[j++]);
      }

      dp[i] = mx + sumPower[i].second;
    }

    mx = 0;

    for (int i = std::max(0, m - 3); i < m; ++i) {
      mx = std::max(mx, dp[i]);
    }

    return mx;
  }
};
