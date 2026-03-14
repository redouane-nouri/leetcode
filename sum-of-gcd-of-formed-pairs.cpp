/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long gcdSum(vector<int> &nums) {
    const int N = nums.size();
    vector<int> prefixGcd;
    prefixGcd.reserve(N);

    int mx = 0;
    for (const int &num : nums) {
      mx = max(mx, num);
      prefixGcd.push_back(gcd(num, mx));
    }

    sort(prefixGcd.begin(), prefixGcd.end());

    long long ans = 0;
    for (int i = 0; i < (N >> 1); ++i)
      ans += gcd(prefixGcd[i], prefixGcd[N - i - 1]);

    return ans;
  }
};
