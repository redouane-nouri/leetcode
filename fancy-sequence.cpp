/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Fancy {
  static constexpr long long MOD = 1e9 + 7;
  long long m = 1, a = 0;
  vector<long long> nums;

public:
  Fancy() {}

  void append(int val) {
    val = (val - a) % MOD;

    if (val < 0)
      val += MOD;

    val = inv(m, MOD - 2) * val % MOD;

    nums.push_back(val);
  }

  void addAll(int inc) { a = a + inc; }

  void multAll(int v) {
    m = m * v % MOD;
    a = a * v % MOD;
  }

  int getIndex(int idx) {
    if (idx >= nums.size())
      return -1;

    return (nums[idx] * m + a) % MOD;
  }

  long long inv(long long b, long long e) {
    long long res = 1;

    while (e) {
      if (e & 1)
        res = res * b % MOD;

      b = b * b % MOD;
      e >>= 1;
    }

    return res;
  }
};
