/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
  ll encode(int a, int b) { return (ll)a << 32 | (unsigned int)b; }

  int eucMod(int a, int b) { return (a % b + abs(b)) % abs(b); };

public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    unordered_set<ll> obsSet;

    for (auto &o : obstacles)
      obsSet.insert(encode(o[0], o[1]));

    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, dir = 0, mx = 0,
        pos[2] = {0, 0};

    for (auto &c : commands) {
      if (c == -1) {
        dir = eucMod(dir + 1, 4);
      } else if (c == -2) {
        dir = eucMod(dir - 1, 4);
      } else {
        for (int i = 0; i < c; ++i) {
          pos[0] += dirs[dir][0], pos[1] += dirs[dir][1];

          if (obsSet.contains(encode(pos[0], pos[1]))) {
            pos[0] -= dirs[dir][0], pos[1] -= dirs[dir][1];
            break;
          }
        }

        mx = max(mx, pos[0] * pos[0] + pos[1] * pos[1]);
      }
    }

    return mx;
  }
};
