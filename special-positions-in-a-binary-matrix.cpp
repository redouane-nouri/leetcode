/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    const int M = mat.size(), N = mat[0].size();
    vector<int> r(M, 0), c(N, 0);

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        r[i] += mat[i][j] == 0;
        c[j] += mat[i][j] == 0;
      }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        ans += (mat[i][j] == 1 && r[i] == N - 1 && c[j] == M - 1);

    return ans;
  }
};
