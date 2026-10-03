/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int ans = 0;

    while (n) {
      n /= 5;
      ans += n;
    }

    return ans;
  }
};
