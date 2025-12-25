#include <algorithm>
#include <vector>

class Solution {
public:
  long long maximumHappinessSum(std::vector<int> &happiness, int k) {
    long long ans = 0;
    std::sort(happiness.begin(), happiness.end(),
              [](const auto &a, const auto &b) { return a > b; });

    for (int i = 0; i < k; ++i)
      ans += std::max(0, happiness[i] - i);

    return ans;
  }
};
