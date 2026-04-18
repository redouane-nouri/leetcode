/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    unordered_map<int, vector<int>> m;
    const int N = nums.size();

    for (int i = 0; i < N; ++i)
      m[nums[i]].push_back(i);

    vector<int> ans;
    ans.reserve(queries.size());

    for (auto &qIdx : queries) {
      auto &p = m[nums[qIdx]];

      if (p.size() == 1) {
        ans.push_back(-1);
        continue;
      }

      int idx = lower_bound(p.begin(), p.end(), qIdx) - p.begin();

      int mn = INT_MAX;

      if (idx + 1 < p.size()) {
        int d = p[idx + 1] - qIdx;
        mn = min({mn, d, N - d});
      }

      if (idx - 1 >= 0) {
        int d = qIdx - p[idx - 1];
        mn = min({mn, d, N - d});
      }

      if (idx == 0 || idx == p.size() - 1)
        mn = min(mn, N - (p.back() - p.front()));

      ans.push_back(mn);
    }

    return ans;
  }
};
