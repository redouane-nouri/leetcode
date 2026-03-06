#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int concatenatedBinary(const int n) {
    const long long MOD = 1e9 + 7;
    long long ans = 0;

    for (unsigned int i = 1; i <= n; ++i)
      ans = ((ans << bit_width(i)) | i) % MOD;

    return ans;
  }
};
