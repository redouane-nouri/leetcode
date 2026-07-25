/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    const int SZ = nums.size();
    int mx = *max_element(nums.begin(), nums.end()), pow2 = 1;

    while (pow2 <= mx)
      pow2 <<= 1;

    vector<bool> pairXor(pow2, false);
    for (int i = 0; i < SZ; ++i)
      for (int j = i; j < SZ; ++j)
        pairXor[nums[i] ^ nums[j]] = true;

    vector<bool> tripletXor(pow2, false);
    for (int v = 0; v < pow2; ++v)
      if (pairXor[v])
        for (int &num : nums)
          tripletXor[num ^ v] = true;

    return count(tripletXor.begin(), tripletXor.end(), true);
  }
};
