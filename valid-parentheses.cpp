/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.size() % 2)
      return false;

    stack<char> st;
    for (const char &ch : s) {
      switch (ch) {
      case '(':
        st.push(')');
        break;

      case '{':
        st.push('}');
        break;

      case '[':
        st.push(']');
        break;

      default:
        if (st.empty() || st.top() != ch)
          return false;

        st.pop();
      }
    }

    return st.empty();
  }
};
