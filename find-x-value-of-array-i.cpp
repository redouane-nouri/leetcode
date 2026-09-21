/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  vector<ll> resultArray(vector<int> &nums, int k) {
    const int N = nums.size();
    vector<int> prevDP(k, 0), currDP(k, 0);

    vector<ll> ans(k, 0);

    for (int i = 0; i < N; ++i) {
      int currRem = nums[i] % k;
      currDP[currRem] = 1;

      for (int rem = 0; rem < k; ++rem)
        currDP[currRem * rem % k] += prevDP[rem];

      for (int rem = 0; rem < k; ++rem)
        ans[rem] += currDP[rem], prevDP[rem] = 0;

      swap(prevDP, currDP);
    }

    return ans;
  }
};
