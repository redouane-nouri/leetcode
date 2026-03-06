#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  char findKthBit(const int n, int k) {
    if (n == 1)
      return '0';

    int l = (1 << n) - 1;
    int m = (l >> 1) + 1;

    if (k == m)
      return '1';
    else if (k < m)
      return findKthBit(n - 1, k);
    else
      return findKthBit(n - 1, l - k + 1) == '0' ? '1' : '0';
  }
};
