/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string smallestSubsequence(string s) {
    const int SZ = s.size();
    int lastIdx[26];

    for (int i = 0; i < SZ; ++i)
      lastIdx[s[i] - 'a'] = i;

    bool isInAns[26];
    string ans;
    for (int i = 0; i < SZ; ++i) {
      const char &c = s[i];

      if (isInAns[c - 'a'])
        continue;

      while (!ans.empty() && ans.back() > c && lastIdx[ans.back() - 'a'] > i)
        isInAns[ans.back() - 'a'] = false, ans.pop_back();

      ans.push_back(c);
      isInAns[c - 'a'] = true;
    }

    return ans;
  }
};
