/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool areSimilar(vector<vector<int>> &mat, int k) {
    const int M = mat.size(), N = mat[0].size();
    auto orignal = mat;
    k %= N;

    const auto eucMod = [](int a, int b) -> int {
      return (a % b + abs(b)) % abs(b);
    };

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        mat[i][j] = orignal[i][i % 2 ? eucMod(j - k, N) : eucMod(j + k, N)];

    return mat == orignal;
  }
};
