#include <algorithm>
#include <array>
#include <string>
#include <vector>

class Solution {
public:
  int findMaxForm(std::vector<std::string> &strs, int m, int n) {
    const int sz = strs.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    std::vector<std::array<int, 2>> zeroesAndOnes;
    zeroesAndOnes.reserve(sz);

    for (auto &str : strs) {
      int z = 0, o = 0;
      for (auto &c : str) {
        switch (c) {
        case '0':
          ++z;
          break;
        case '1':
          ++o;
          break;
        }
      }

      zeroesAndOnes.push_back({z, o});
    }

    dp[0][0] = 0;

    for (auto &zo : zeroesAndOnes) {
      for (int i = m; i >= zo[0]; --i) {
        for (int j = n; j >= zo[1]; --j) {
          dp[i][j] = std::max(dp[i][j], dp[i - zo[0]][j - zo[1]] + 1);
        }
      }
    }

    return dp[m][n];
  }
};
