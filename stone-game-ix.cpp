/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool stoneGameIX(vector<int> &stones) {
    int r0 = 0, r1 = 0, r2 = 0;

    for (const int &v : stones)
      if (int rm = v % 3; rm == 0)
        ++r0;
      else if (rm == 1)
        ++r1;
      else
        ++r2;

    if (r0 % 2 == 0)
      return r1 >= 1 && r2 >= 1;

    return abs(r1 - r2) > 2;
  }
};
