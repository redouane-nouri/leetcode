/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
  struct Interval {
    int l, r, w, i;
  };

  struct State {
    ll w = 0;
    vector<int> idxs;
  };

public:
  vector<int> maximumWeight(vector<vector<int>> &intervals) {
    vector<Interval> intrvls;
    const int N = intervals.size();

    for (int i = 0; auto &in : intervals)
      intrvls.push_back({in[0], in[1], in[2], i++});

    sort(intrvls.begin(), intrvls.end(),
         [](auto &a, auto &b) -> bool { return a.r < b.r; });

    vector dp(N + 1, vector<State>(5));

    for (int i = 0; i < N; ++i) {
      auto &cur = intrvls[i];
      int idx = lower_bound(intrvls.begin(), intrvls.begin() + i, cur.l,
                            [](const auto &in, const int &l) -> bool {
                              return in.r < l;
                            }) -
                intrvls.begin();

      for (int cnt = 1; cnt <= 4; ++cnt) {
        const State &skip = dp[i][cnt];
        ll takeW = dp[idx][cnt - 1].w + cur.w;

        if (takeW < skip.w) {
          dp[i + 1][cnt] = skip;
          continue;
        }

        vector<int> withCur = dp[idx][cnt - 1].idxs;
        withCur.push_back(cur.i);
        sort(withCur.begin(), withCur.end());

        bool tie = takeW == skip.w;
        dp[i + 1][cnt].w = takeW;
        dp[i + 1][cnt].idxs =
            (tie && skip.idxs < withCur) ? skip.idxs : withCur;
      }
    }

    return dp[N][4].idxs;
  }
};
