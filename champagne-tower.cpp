#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
  double champagneTower(int poured, int query_row, int query_glass) {
    double dp[5050][2] = {0.0, 0.0};

    dp[0][0] = min(1.0 * poured, 1.0);
    dp[0][1] = max(0.0, 1.0 * poured - 1.0) / 2;

    for (int r = 1; r <= query_row; ++r) {
      for (int i = 0; i <= r; ++i) {
        int idx = (r * (r + 1) >> 1) + i;
        int pIdx = ((r - 1) * r >> 1) + i;

        double parentExcess = dp[pIdx][1];
        double &currFilled = dp[idx][0];
        double &currExcess = dp[idx][1];

        if (i != r) {
          currFilled = min(1.0, parentExcess);
          currExcess = max(0.0, parentExcess - currFilled) / 2;
        }

        if (i != 0) {
          parentExcess = dp[pIdx - 1][1];
          double empty = 1.0 - currFilled;

          currFilled += min(empty, parentExcess);
          currExcess += (parentExcess - min(empty, parentExcess)) / 2;
        }
      }
    }

    return dp[(query_row * (query_row + 1) >> 1) + query_glass][0];
  }
};
