/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll encode(int a, int b) { return (ll)a << 32 | (unsigned int)b; }

class Solution {
public:
  int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
    const int N = img1.size();
    vector<pair<int, int>> ones1, ones2;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (img1[i][j])
          ones1.push_back({i, j});

        if (img2[i][j])
          ones2.push_back({i, j});
      }
    }

    unordered_map<ll, int> cnt;
    int ans = 0;

    for (auto &p1 : ones1) {
      for (auto &p2 : ones2) {
        int dx = p2.first - p1.first, dy = p2.second - p1.second;
        ans = max(ans, ++cnt[encode(dx, dy)]);
      }
    }

    return ans;
  }
};
