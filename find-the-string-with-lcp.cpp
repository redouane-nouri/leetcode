/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string findTheString(vector<vector<int>> &lcp) {
    const int N = lcp.size();
    string w(N, '\0');
    char c = 'a';

    for (int i = 0; i < N; ++i) {
      if (w[i] == '\0') {
        if (c > 'z')
          return "";

        w[i] = c;
        for (int j = i + 1; j < N; ++j)
          if (lcp[i][j])
            w[j] = c;

        ++c;
      }
    }

    for (int i = N - 1; i >= 0; --i) {
      for (int j = N - 1; j >= 0; --j) {
        int res =
            w[i] != w[j]
                ? 0
                : ((i == N - 1 || j == N - 1) ? 1 : lcp[i + 1][j + 1] + 1);

        if (lcp[i][j] != res)
          return "";
      }
    }

    return w;
  }
};
