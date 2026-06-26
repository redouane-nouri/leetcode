/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    const int N = nums.size();
    vector<int> pre((N << 1) + 1, 0);
    int acc = 0, idx = N;
    long long ans = 0;

    pre[N] = 1;
    for (int i = 0; i < N; ++i) {
      if (nums[i] == target) {
        acc += pre[idx];
        ++idx;
        ++pre[idx];
      } else {
        --idx;
        acc -= pre[idx];
        ++pre[idx];
      }

      ans += acc;
    }

    return ans;
  }
};
