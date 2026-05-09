/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  struct Comp {
    int v, l, r;
  };

  vector<int> maxValue(const vector<int> &nums) {
    const int N = nums.size();
    vector<int> ans(N, 0);
    vector<Comp> st;

    for (int i = 0; i < N; ++i) {
      Comp curr = {nums[i], i, i};

      while (!st.empty() && st.back().v > nums[i]) {
        Comp top = st.back();
        st.pop_back();
        curr.v = max(curr.v, top.v);
        curr.l = top.l;
      }

      st.push_back(curr);
    }

    for (int i = 0; i < st.size(); ++i)
      for (int j = st[i].l; j <= st[i].r; ++j)
        ans[j] = st[i].v;

    return ans;
  }
};
