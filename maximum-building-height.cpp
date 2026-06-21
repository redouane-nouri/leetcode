/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxBuilding(const int N, vector<vector<int>> &r) {
    r.push_back({1, 0}), r.push_back({N, N - 1});

    const int M = r.size();
    if (M == 2)
      return N - 1;

    sort(r.begin(), r.end(),
         [](const vector<int> &a, const vector<int> &b) -> bool {
           return a[0] < b[0];
         });

    for (int i = 1; i < M; ++i)
      r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);

    for (int i = M - 2; i >= 1; --i)
      r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);

    int ans = r[0][1];
    for (int i = 1; i < M; ++i)
      ans = max(ans, (r[i][0] - r[i - 1][0] + r[i][1] + r[i - 1][1]) >> 1);

    return ans;
  }
};
