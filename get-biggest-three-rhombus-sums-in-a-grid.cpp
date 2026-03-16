/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();

    int m1, m2, m3;
    m1 = m2 = m3 = INT_MIN;

    const auto compareMaximums = [&m1, &m2, &m3](int &s) -> void {
      if (s == m1 || s == m2 || s == m3)
        return;

      if (s > m1) {
        m3 = m2;
        m2 = m1;
        m1 = s;
      } else if (s > m2) {
        m3 = m2;
        m2 = s;
      } else if (s > m3) {
        m3 = s;
      }
    };

    const auto computeRhombusSums = [&m1, &m2, &m3, &grid, &M, &N,
                                     &compareMaximums](int i, int j) -> void {
      int l = 1, upper = grid[i][j];

      while (j - l >= 0 && j + l < N && (i + (l << 1)) < M) {
        upper += grid[i + l][j + l] + grid[i + l][j - l];

        int bottom = grid[i + (l << 1)][j];
        int lft = j - l + 1, rght = j + l - 1, row = i + l + 1;

        while (lft < rght) {
          bottom += grid[row][lft++] + grid[row][rght--];
          ++row;
        }

        int s = upper + bottom;

        compareMaximums(s);
        ++l;
      }
    };

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        compareMaximums(grid[i][j]), computeRhombusSums(i, j);

    vector<int> res;

    if (m1 != INT_MIN)
      res.push_back(m1);

    if (m2 != INT_MIN)
      res.push_back(m2);

    if (m3 != INT_MIN)
      res.push_back(m3);

    return res;
  }
};
