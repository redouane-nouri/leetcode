/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string generateString(string str1, string str2) {
    const int N = str1.size(), M = str2.size();
    string s(N + M - 1, 'a');
    vector<bool> hasT(N + M - 1, false);

    for (int i = 0; i < N; ++i) {
      if (str1[i] == 'T') {
        for (int j = i; j < i + M; ++j) {
          if (hasT[j] && s[j] != str2[j - i])
            return "";

          s[j] = str2[j - i];
          hasT[j] = true;
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      if (str1[i] == 'F') {
        bool matches = true;
        int idx = -1;

        for (int j = i + M - 1; j >= i && matches; --j) {
          if (s[j] != str2[j - i])
            matches = false;

          if (idx == -1 && !hasT[j])
            idx = j;
        }

        if (matches) {
          if (idx == -1)
            return "";

          s[idx] = 'b';
        }
      }
    }

    return s;
  }
};
