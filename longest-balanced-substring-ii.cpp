#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestBalanced(string s) {
    const int N = s.size();
    int mx = 1;
    int l = 1;

    for (int i = 1; i < N; i++) {
      if (s[i] == s[i - 1]) {
        l++;
      } else {
        mx = max(mx, l);
        l = 1;
      }
    }

    mx = max(mx, l);

    const auto twoChars = [&mx, &s, &N](const char x, const char y) -> void {
      int sum = 0;
      unordered_map<int, int> mp;
      mp[0] = -1;

      for (int i = 0; i < N; ++i) {
        if (s[i] == x) {
          sum += 1;
        } else if (s[i] == y) {
          sum -= 1;
        } else {
          mp.clear();
          mp[0] = i;
          sum = 0;
          continue;
        }

        if (mp.count(sum))
          mx = max(mx, i - mp[sum]);
        else
          mp[sum] = i;
      }
    };

    twoChars('a', 'b');
    twoChars('b', 'c');
    twoChars('a', 'c');

    map<pair<int, int>, int> mp;
    mp[{0, 0}] = -1;
    int freq[3] = {0};

    for (int i = 0; i < N; ++i) {
      ++freq[s[i] - 'a'];

      int diffAB = freq[0] - freq[1];
      int diffAC = freq[0] - freq[2];

      if (mp.count({diffAB, diffAC}))
        mx = max(mx, i - mp[{diffAB, diffAC}]);
      else
        mp[{diffAB, diffAC}] = i;
    }

    return mx;
  }
};
