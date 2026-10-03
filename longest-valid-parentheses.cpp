/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    const int SZ = s.length();
    int ans = 0;
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < SZ; ++i) {
      switch (s[i]) {
      case '(':
        st.push(i);
        break;

      default:
        st.pop();

        if (st.empty())
          st.push(i);
        else
          ans = max(ans, i - st.top());
      }
    }

    return ans;
  }
};
