/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxWalls(vector<int> &robots, vector<int> &distance, vector<int> &walls) {
    const int N = robots.size();

    vector<int> idxs(N);

    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(),
         [&robots](auto &i, auto &j) { return robots[i] < robots[j]; });
    sort(walls.begin(), walls.end());

    auto lb = [&walls](int v) {
      return (int)(lower_bound(walls.begin(), walls.end(), v) - walls.begin());
    };
    auto ub = [&walls](int v) {
      return (int)(upper_bound(walls.begin(), walls.end(), v) - walls.begin());
    };

    vector<int> l(N), r(N), o(N);

    for (int i = 0; i < N; ++i) {
      int &idx = idxs[i], &pos = robots[idx], &d = distance[idx];

      int wr = ub(pos);
      int lmax = (i > 0) ? max(pos - d, robots[idxs[i - 1]] + 1) : pos - d;

      l[i] = wr - lb(lmax);

      int rmax = (i < N - 1) ? min(pos + d, robots[idxs[i + 1]] - 1) : pos + d;
      r[i] = ub(rmax) - lb(pos);

      if (i > 0)
        o[i] = wr - lb(robots[idxs[i - 1]]);
    }

    int bl = l[0];
    int br = r[0];

    for (int i = 1; i < N; ++i) {
      int nbl = max(bl + l[i], br - r[i - 1] + min(l[i] + r[i - 1], o[i]));
      int nbr = max(bl + r[i], br + r[i]);

      bl = nbl;
      br = nbr;
    }

    return max(bl, br);
  }
};
