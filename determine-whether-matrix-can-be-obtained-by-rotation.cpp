/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    if (mat == target)
      return true;

    const int N = mat.size();

    const auto rotate = [&N, &mat]() -> void {
      vector<vector<int>> res(N, vector<int>(N));

      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          res[j][N - i - 1] = mat[i][j];

      mat = res;
    };

    for (int i = 1; i <= 3; ++i) {
      rotate();

      if (mat == target)
        return true;
    }

    return false;
  }
};
