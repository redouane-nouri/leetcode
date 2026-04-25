/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  int maxDistance(int side, vector<vector<int>> &points, int k) {
    vector<ll> mnhtn;
    mnhtn.reserve(points.size());

    for (auto &p : points) {
      int &x = p[0], &y = p[1];
      if (x == 0)
        mnhtn.push_back(y);
      else if (y == side)
        mnhtn.push_back(side + x);
      else if (x == side)
        mnhtn.push_back(side * 3LL - y);
      else
        mnhtn.push_back(side * 4LL - x);
    }

    sort(mnhtn.begin(), mnhtn.end());

    auto isValid = [&mnhtn, &side, &k](int l) -> bool {
      for (ll &fst : mnhtn) {
        ll lst = fst + side * 4LL - l, cur = fst;

        for (int i = 0; i < k - 1 && cur != -1; ++i) {
          auto it = lower_bound(mnhtn.begin(), mnhtn.end(), cur + l);

          cur = (it == mnhtn.end() || *it > lst) ? -1 : *it;
        }

        if (cur != -1)
          return true;
      }

      return false;
    };

    int l = 0, r = side + 1;

    while (l < r) {
      int m = l + (r - l >> 1);

      isValid(m) ? l = m + 1 : r = m;
    }

    return l - 1;
  }
};
