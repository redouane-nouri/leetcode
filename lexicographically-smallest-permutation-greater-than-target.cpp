/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  string lexGreaterPermutation(string s, string target) {
    const int SZ = s.size();
    vector<int> cnt(26, 0);

    for (int i = 0; i < SZ; ++i)
      ++cnt[s[i] - 'a'], --cnt[target[i] - 'a'];

    auto buildSuffix = [&cnt]() -> string {
      string res;

      for (int i = 0; i < 26; ++i)
        res.append(cnt[i], 'a' + i);

      return res;
    };

    for (int i = SZ - 1; i >= 0; --i) {
      int j = target[i] - 'a';
      ++cnt[j];

      if (*min_element(cnt.begin(), cnt.end()) < 0)
        continue;

      for (int k = j + 1; k < 26; ++k) {
        if (cnt[k]) {
          --cnt[k];
          target[i] = 'a' + k;
          target.resize(i + 1);
          return target + buildSuffix();
        }
      }
    }

    return "";
  }
};
