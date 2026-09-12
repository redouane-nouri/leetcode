/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxValidSplits(vector<int> &nums) {
    const auto calcScore = [](const vector<int> &nums) -> int {
      const int N = nums.size();

      if (N < 2)
        return 0;

      vector<int> pre(N), suf(N);
      pre[0] = nums[0];
      for (int i = 1; i < N; ++i)
        pre[i] = gcd(pre[i - 1], nums[i]);

      suf[N - 1] = nums[N - 1];
      for (int i = N - 2; i >= 0; --i)
        suf[i] = gcd(suf[i + 1], nums[i]);

      int score = 0;
      for (int i = 0; i < N - 1; ++i)
        if (pre[i] == suf[i + 1])
          ++score;

      return score;
    };

    int ans = calcScore(nums);
    const int N = nums.size();

    for (int i = 0; i < N; ++i) {
      vector<int> tmp;
      tmp.reserve(N - 1);

      for (int j = 0; j < N; ++j)
        if (i != j)
          tmp.push_back(nums[j]);

      ans = max(ans, calcScore(tmp));
    }
    return ans;
  }
};
