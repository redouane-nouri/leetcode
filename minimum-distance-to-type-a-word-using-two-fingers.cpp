/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumDistance(string word) {
    const int N = word.size();
    vector<int> dp(26, 0);
    int s = 0, mx = 0;

    for (int i = 0; i < N - 1; i++) {
      int a = word[i] - 'A', b = word[i + 1] - 'A', d = dist(a, b);

      s += d;

      int cr = 0;
      for (int c = 0; c < 26; c++)
        cr = max(cr, dp[c] + d - dist(b, c));

      dp[a] = max(dp[a], cr);
      mx = max(mx, dp[a]);
    }

    return s - mx;
  }

private:
  int dist(int a, int b) { return abs(a / 6 - b / 6) + abs(a % 6 - b % 6); }
};
