/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int mx1 = 0, mx2 = 0;

    for (int &num : nums)
      mx2 = max(mx2, min(mx1, num)), mx1 = max(mx1, num);

    return --mx1 * --mx2;
  }
};
