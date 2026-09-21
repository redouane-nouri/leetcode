/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  struct Interval {
    int l, r;

    bool operator<(const Interval &rhs) const {
      if (r == rhs.r)
        return l > rhs.l;

      return r < rhs.r;
    }
  };

public:
  vector<string> maxNumOfSubstrings(string s) {
    vector<Interval> intervals(26, {-1, -1});

    const int N = s.size();
    for (int i = 0; i < N; ++i) {
      int idx = s[i] - 'a';

      if (intervals[idx].l == -1)
        intervals[idx] = {i, i};
      else
        intervals[idx].r = i;
    }

    for (int i = 0; i < 26; ++i) {
      if (intervals[i].l == -1)
        continue;

      for (int left = intervals[i].l; left <= intervals[i].r; ++left) {
        int idx = s[left] - 'a';

        if (intervals[i].l <= intervals[idx].l &&
            intervals[i].r >= intervals[idx].r)
          continue;

        intervals[i].l = min(intervals[i].l, intervals[idx].l);
        intervals[i].r = max(intervals[i].r, intervals[idx].r);
        left = intervals[i].l;
      }
    }

    sort(intervals.begin(), intervals.end());
    vector<string> ans;

    int last = -1;
    for (int i = 0; i < 26; ++i) {
      if (intervals[i].l == -1)
        continue;

      if (intervals[i].l > last) {
        last = intervals[i].r;
        ans.push_back(
            s.substr(intervals[i].l, intervals[i].r - intervals[i].l + 1));
      }
    }

    return ans;
  }
};
