/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int ans = 0, curr = 0;

    for (int &g : gain)
      curr += g, ans = max(ans, curr);

    return ans;
  }
};
