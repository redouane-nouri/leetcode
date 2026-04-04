/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> survivedRobotsHealths(vector<int> &positions,
                                    vector<int> &healths, string directions) {
    const int N = positions.size();
    vector<int> idxs(N);

    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(),
         [&positions](int &a, int &b) { return positions[a] < positions[b]; });

    stack<int> st;

    for (int &idx : idxs) {
      if (directions[idx] == 'R') {
        st.push(idx);
      } else {
        while (!st.empty() && healths[idx]) {
          int topIdx = st.top();
          st.pop();

          int &ht = healths[topIdx], &hc = healths[idx];

          if (hc < ht)
            --ht, hc = 0, st.push(topIdx);
          else if (hc > ht)
            ht = 0, --hc;
          else
            ht = 0, hc = 0;
        }
      }
    }

    vector<int> ans;

    for (int i = 0; i < N; ++i)
      if (healths[i])
        ans.push_back(healths[i]);

    return ans;
  }
};
