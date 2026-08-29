/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string lexPalindromicPermutation(string s, string target) {
    const int SZ = target.size();
    vector<int> cnt(26, 0);

    for (int i = 0; i < SZ; ++i)
      ++cnt[s[i] - 'a'];

    char m = '\0';
    for (int i = 0; i < 26; ++i)
      if (cnt[i] % 2)
        if (!m)
          m = 'a' + i, --cnt[i];
        else
          return "";

    for (int i = 0; i < (SZ >> 1); ++i)
      cnt[target[i] - 'a'] -= 2;

    if (*min_element(cnt.begin(), cnt.end()) >= 0) {
      string frst = target.substr(0, SZ >> 1), rev = frst, last = "";

      reverse(rev.begin(), rev.end());

      if (m)
        last += m;

      last += rev;

      if (last > target.substr(SZ >> 1))
        return frst + last;
    }

    for (int i = (SZ >> 1) - 1; i >= 0; --i) {
      int j = target[i] - 'a';
      cnt[j] += 2;

      if (*min_element(cnt.begin(), cnt.end()) < 0)
        continue;

      for (int k = j + 1; k < 26; ++k) {
        if (cnt[k] == 0)
          continue;

        cnt[k] -= 2;
        string frst = target.substr(0, i + 1);
        frst[i] = 'a' + k;

        for (int l = 0; l < 26; ++l)
          frst.append(cnt[l] >> 1, 'a' + l);

        string last = frst;
        reverse(last.begin(), last.end());

        if (m)
          frst += m;

        return frst + last;
      }
    }

    return "";
  }
};
