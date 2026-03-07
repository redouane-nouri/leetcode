#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    const int N = grid.size();
    vector<int> zs(N, 0);

    for (int i = 0; i < N; ++i) {
      int j = N - 1;

      while (j >= 0 && grid[i][j] == 0)
        --j;

      zs[i] = N - 1 - j;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int need = N - 1 - i;
      int j = i;

      while (j < N && zs[j] < need)
        ++j;

      if (j == N)
        return -1;

      while (j > i) {
        swap(zs[j], zs[j - 1]);
        --j;
        ++ans;
      }
    }

    return ans;
  }
};
