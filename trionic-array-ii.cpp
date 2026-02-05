#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maxSumTrionic(vector<int> &nums) {
    const int M = nums.size();
    vector<pair<int, int>> inc, dec;
    vector<long long> preSum(M + 1);
    preSum[0] = 0;

    for (int i = 0; i < M; ++i)
      preSum[i + 1] = preSum[i] + nums[i];

    greater<int> isGreater;
    less<int> isLess;

    int i = 0;
    const auto processSeq = [&M, &nums, &i](auto comp) -> void {
      while (i < M - 1 && comp(nums[i], nums[i + 1]))
        ++i;
    };

    while (i < M - 1) {
      int start = i;
      if (nums[i] < nums[i + 1])
        processSeq(isLess), inc.push_back({start, i});
      else if (nums[i] > nums[i + 1])
        processSeq(isGreater), dec.push_back({start, i});
      else
        ++i;
    }

    const int N = inc.size(), O = dec.size();
    long long ans = LLONG_MIN;
    i = 0;
    int j = 0;

    while (i < N - 1 && j < O) {
      int ic1 = inc[i].second;
      int dc1 = dec[j].first;
      int dc2 = dec[j].second;
      int ic2 = inc[i + 1].first;

      if (ic1 == dc1 && dc2 == ic2) {
        --ic1;
        ++ic2;

        while (ic1 - 1 >= inc[i].first && nums[ic1 - 1] > 0)
          --ic1;

        long long cur = 0, best = LLONG_MIN;

        for (int k = ic2; k <= inc[i + 1].second; ++k) {
          cur += nums[k];
          if (cur > best) {
            best = cur;
            ic2 = k;
          }
        }

        ans = max(ans, preSum[ic2 + 1] - preSum[ic1]);

        ++i;
        ++j;
      } else {
        ic1 < dc1 ? ++i : ++j;
      }
    }
    return ans;
  }
};
