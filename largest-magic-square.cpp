#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int largestMagicSquare(vector<vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<int>> preSumRows(M, vector<int>(N + 1)),
        preSumCols(M + 1, vector<int>(N)),
        preSumDiag1(M + 1, vector<int>(N + 1)),
        preSumDiag2(M + 1, vector<int>(N + 1));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        preSumRows[i][j + 1] = preSumRows[i][j] + grid[i][j];
        preSumCols[i + 1][j] = preSumCols[i][j] + grid[i][j];
        preSumDiag1[i + 1][j + 1] = preSumDiag1[i][j] + grid[i][j];
        preSumDiag2[i + 1][j] = preSumDiag2[i][j + 1] + grid[i][j];
      }
    }
    for (int k = min(M, N); k >= 2; --k) {
      for (int i = 0; i + k <= M; ++i) {
        for (int j = 0; j + k <= N; ++j) {
          int sum = preSumRows[i][j + k] - preSumRows[i][j];
          bool isMagic = true;
          for (int l = 0; l < k && isMagic; ++l)
            isMagic =
                (preSumRows[i + l][j + k] - preSumRows[i + l][j] == sum) &&
                (preSumCols[i + k][j + l] - preSumCols[i][j + l] == sum);

          isMagic &= (preSumDiag1[i + k][j + k] - preSumDiag1[i][j] == sum) &&
                     (preSumDiag2[i + k][j] - preSumDiag2[i][j + k] == sum);

          if (isMagic)
            return k;
        }
      }
    }

    return 1;
  }
};
