/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  vector<int> buildLPS(string &pattern) {
    const int N = pattern.size();
    int prefixLen = 0, i = 1;
    vector<int> lps(N);
    lps[0] = 0;

    while (i < N)
      if (pattern[i] == pattern[prefixLen])
        ++prefixLen, lps[i] = prefixLen, ++i;
      else
        prefixLen ? (prefixLen = lps[prefixLen - 1]) : (lps[i] = 0, ++i);

    return lps;
  }

  vector<int> kmpSearch(string &text, string &pattern) {
    vector<int> matches;
    const int N = text.size(), M = pattern.size();

    if (!M)
      return matches;

    auto lps = buildLPS(pattern);

    int i = 0, j = 0;
    while (i < N) {
      if (text[i] == pattern[j]) {
        ++i, ++j;
        if (j == M)
          matches.push_back(i - j), j = lps[j - 1];
      } else {
        j ? j = lps[j - 1] : ++i;
      }
    }

    return matches;
  }

public:
  int numOfStrings(vector<string> &patterns, string word) {
    int ans = 0;

    for (auto &p : patterns) {
      auto matches = kmpSearch(word, p);

      if (matches.size())
        ++ans;
    }

    return ans;
  }
};
