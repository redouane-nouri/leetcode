#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    const int M = mat.size(), N = mat[0].size();
    vector<vector<int>> preSum(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= M; ++i)
      for (int j = 1; j <= N; ++j)
        preSum[i][j] = preSum[i][j - 1] + preSum[i - 1][j] -
                       preSum[i - 1][j - 1] + mat[i - 1][j - 1];
    const auto getSum = [&preSum](int xt, int yt, int xb, int yb) -> int {
      return (preSum[xb][yb] - preSum[xt - 1][yb] - preSum[xb][yt - 1] +
              preSum[xt - 1][yt - 1]);
    };
    int limit = min(M, N), delta = 0;
    for (int i = 1; i + delta <= M; ++i)
      for (int j = 1; j + delta <= N; ++j)
        for (int k = delta; k <= limit && i + delta <= M && j + delta <= N &&
                            getSum(i, j, i + k, j + k) <= threshold;
             ++k)
          ++delta;
    return delta;
  }
};
