#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

class Solution {
  const int MOD = 1'000'000'007;

public:
  int countPartitions(std::vector<int> &nums, int k) {
    const int N = nums.size();
    std::vector<int> dp(N + 1, 0), pref(N + 1, 0);
    std::multiset<int> window;

    dp[0] = 1;
    pref[0] = 1;

    for (int i = 0, j = 0; i < N; ++i) {
      window.emplace(nums[i]);
      while (j <= i && *window.rbegin() - *window.begin() > k) {
        window.erase(window.find(nums[j]));
        ++j;
      }

      if (j == 0)
        dp[i + 1] = pref[i];
      else
        dp[i + 1] = (pref[i] - pref[j - 1] + MOD) % MOD;

      pref[i + 1] = (pref[i] + dp[i + 1]) % MOD;
    }

    return dp[N];
  }
};
