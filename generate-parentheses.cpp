/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  void generate(int o, int c, int n, string &curr, vector<string> &res) {
    if (o == n && o == c) {
      res.push_back(curr);
      return;
    }

    if (o < n) {
      curr.push_back('(');
      generate(o + 1, c, n, curr, res);
      curr.pop_back();
    }

    if (c < o) {
      curr.push_back(')');
      generate(o, c + 1, n, curr, res);
      curr.pop_back();
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string curr;

    generate(0, 0, n, curr, res);

    return res;
  }
};
