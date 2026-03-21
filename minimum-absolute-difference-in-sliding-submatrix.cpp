/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, const int k) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<int>> ans(M - k + 1, vector<int>(N - k + 1));

    for (int i = 0; i < M - k + 1; ++i) {
      for (int j = 0; j < N - k + 1; ++j) {
        vector<int> sub;

        for (int r = i; r < i + k; r++)
          for (int c = j; c < j + k; c++)
            sub.push_back(grid[r][c]);

        sort(sub.begin(), sub.end());
        auto end = unique(sub.begin(), sub.end());

        int mn = INT_MAX;
        for (auto it = sub.begin() + 1; it != end; ++it)
          mn = min(mn, *it - *(it - 1));

        ans[i][j] = mn == INT_MAX ? 0 : mn;
      }
    }

    return ans;
  }
};
