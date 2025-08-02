#include <algorithm>
#include <climits>
#include <functional>
#include <unordered_map>
#include <vector>

class Solution {
public:
  long long minCost(std::vector<int> &basket1, std::vector<int> &basket2) {
    int sz = basket1.size(), minFruit = INT_MAX;
    std::unordered_map<int, int> freq;

    for (int i = 0; i < sz; ++i) {
      ++freq[basket1[i]];
      --freq[basket2[i]];
      minFruit = std::min({minFruit, basket1[i], basket2[i]});
    }

    std::vector<std::pair<int, int>> toSwap1, toSwap2;

    for (std::pair<const int, int> &pair : freq) {
      if (pair.second == 0)
        continue;

      if (pair.second % 2 != 0)
        return -1;

      pair.second > 0 ? toSwap1.push_back(pair) : toSwap2.push_back(pair);
    }

    std::sort(toSwap1.begin(), toSwap1.end());
    std::sort(toSwap2.begin(), toSwap2.end(),
              std::greater<std::pair<int, int>>());

    int j = 0;
    long long cost = 0;

    sz = toSwap1.size();

    for (int i = 0; i < sz; ++i) {
      while (toSwap1[i].second != 0) {
        cost += std::min(
            {1LL * toSwap1[i].first, 1LL * toSwap2[j].first, 2LL * minFruit});

        toSwap1[i].second -= 2;
        toSwap2[j].second += 2;

        if (toSwap2[j].second == 0)
          ++j;
      }
    }

    return cost;
  }
};
