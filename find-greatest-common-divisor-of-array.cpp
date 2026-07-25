/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findGCD(vector<int> &nums) {
    int mx = INT_MIN, mn = INT_MAX;

    for (int &num : nums)
      mx = max(mx, num), mn = min(mn, num);

    return gcd(mx, mn);
  }
};
