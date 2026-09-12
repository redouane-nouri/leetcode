/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool uniformArray(vector<int> &nums1) {
    if (*min_element(nums1.begin(), nums1.end()) & 1)
      return true;

    if (any_of(nums1.begin(), nums1.end(),
               [](const int &x) -> bool { return x & 1; }))
      return false;

    return true;
  }
};
