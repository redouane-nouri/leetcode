/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
      auto getWaviness = [](int &num) -> int {
        string s = to_string(num);

        int ans = 0;
        for(int i = 1; i < s.size() - 1; ++i)
          if((s[i - 1] < s[i] && s[i] > s[i + 1]) || (s[i - 1] > s[i] && s[i] < s[i + 1]))
            ++ans;

        return ans;
      };

      int res = 0;
      for(int i = num1; i <= num2; ++i)
        res += getWaviness(i);

      return res;
    }
};
