#include <vector>

class Solution {
public:
  int countNegatives(std::vector<std::vector<int>> &grid) {
    const int N = grid[0].size();

    int ans = 0;
    for (auto &r : grid) {
      for (int i = 0; i < N; ++i) {
        if (r[i] < 0) {
          ans += N - i;
          break;
        }
      }
    }

    return ans;
  }
};
