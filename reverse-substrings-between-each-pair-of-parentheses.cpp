/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string reverseParentheses(string s) {
    const int N = s.size();
    stack<int> open;
    vector<int> pair(N);

    for (int i = 0; i < N; ++i) {
      if (s[i] == '(') {
        open.push(i);
      } else if (s[i] == ')') {
        int j = open.top();
        open.pop();

        pair[i] = j;
        pair[j] = i;
      }
    }

    string res;
    res.reserve(N);
    for (int i = 0, dir = 1; i < N; i += dir) {
      if (s[i] == '(' || s[i] == ')') {
        dir = -dir;
        i = pair[i];
      } else {
        res += s[i];
      }
    }

    return res;
  }
};
