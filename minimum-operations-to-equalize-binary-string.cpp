#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minOperations(string s, int k) {
    const int N = s.size();
    int z = 0;
    set<int> sets[2];

    for (int i = 0; i < N; ++i) {
      sets[i % 2].insert(i);

      if (s[i] == '0')
        ++z;
    }

    sets[N % 2].insert(N);

    queue<int> q;
    vector<int> dist(N + 1, INT_MAX);

    q.push(z);
    dist[z] = 0;
    sets[z % 2].erase(z);

    while (!q.empty()) {
      z = q.front();
      q.pop();

      int mnz = max(k - N + z, 0);
      int mxz = min(k, z);

      int l = z + k - (mxz << 1);
      int r = z + k - (mnz << 1);

      set<int> &paritySet = sets[l % 2];

      for (auto it = paritySet.lower_bound(l);
           it != paritySet.end() && *it <= r;) {
        dist[*it] = dist[z] + 1;
        q.push(*it);
        it = next(it);
        paritySet.erase(prev(it));
      }
    }

    return dist[0] == INT_MAX ? -1 : dist[0];
  }
};
