/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    const int M = matrix.size(), N = matrix[0].size();

    for (int i = 1; i < M; ++i)
      for (int j = 0; j < N; ++j)
        if (matrix[i][j])
          matrix[i][j] += matrix[i - 1][j];

    int ans = 0;

    for (auto &r : matrix) {
      sort(r.begin(), r.end());

      for (int i = N - 1; i >= 0; --i)
        ans = max(ans, r[i] * (N - i));
    }

    return ans;
  }
};
