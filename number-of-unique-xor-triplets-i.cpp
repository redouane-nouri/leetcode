/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    const int SZ = nums.size();

    if (SZ <= 2)
      return SZ;

    int ans = 1;
    while (ans <= SZ)
      ans <<= 1;

    return ans;
  }
};
