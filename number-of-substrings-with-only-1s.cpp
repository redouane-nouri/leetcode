#include <string>

class Solution {
  static constexpr long long MOD = 1000000007LL;

public:
  int numSub(std::string s) {
    long long res = 0, onesCnt = 0;
    int i = 0;

    for (char &c : s) {
      if (c == '0') {
        res += onesCnt * (onesCnt + 1) / 2;
        onesCnt = 0;
      } else {
        ++onesCnt;
      }
    }

    res += onesCnt * (onesCnt + 1) / 2;

    return res % MOD;
  }
};
