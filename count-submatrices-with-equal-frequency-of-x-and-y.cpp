/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<int>> freq(M + 1, vector<int>(N + 1, 0));
    vector<vector<bool>> hasXorY(M + 1, vector<bool>(N + 1, false));

    const auto getValue = [](const char &c) -> int {
      switch (c) {
      case 'X':
        return 1;

      case 'Y':
        return -1;

      default:
        return 0;
      }
    };

    const auto isXorY = [](const char &c) -> bool {
      return c == 'X' || c == 'Y';
    };

    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
        freq[i][j] = freq[i][j - 1] - freq[i - 1][j - 1] + freq[i - 1][j] +
                     getValue(grid[i - 1][j - 1]);
        hasXorY[i][j] = isXorY(grid[i - 1][j - 1]) || hasXorY[i - 1][j] ||
                        hasXorY[i][j - 1];
      }
    }

    int ans = 0;
    for (int i = 1; i <= M; ++i)
      for (int j = 1; j <= N; ++j)
        if (!freq[i][j] && hasXorY[i][j])
          ++ans;

    return ans;
  }
};
