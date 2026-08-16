/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> validSequence(string word1, string word2) {
    const int SZ1 = word1.size(), SZ2 = word2.size();
    vector<int> sufMatch(SZ2, -1);

    for (int i = SZ1 - 1, j = SZ2 - 1; i >= 0 && j >= 0; --i)
      if (word1[i] == word2[j])
        sufMatch[j] = i, --j;

    vector<int> res;
    res.reserve(SZ2);
    bool skipUsed = false;
    int j = 0;

    for (int i = 0; i < SZ1 && j < SZ2 && SZ1 - i >= SZ2 - j; ++i) {
      bool match = word1[i] == word2[j],
           canSkip = !skipUsed && (j == SZ2 - 1 || i < sufMatch[j + 1]);

      if (match || canSkip) {
        if (!match)
          skipUsed = true;

        res.push_back(i);
        ++j;
      }
    }

    if (j == SZ2)
      return res;

    return {};
  }
};
