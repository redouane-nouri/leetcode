#include <algorithm>
#include <vector>

class Solution {
public:
  int maxTotalFruits(std::vector<std::vector<int>> &fruits, int startPos,
                     int k) {
    int n = fruits.size(), mx = 0;
    std::vector<int> positions(n), prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      positions[i] = fruits[i][0];
      prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
    }

    for (int steps = 0; steps <= k; ++steps) {
      int left = startPos - steps;
      int right = startPos + (k - 2 * steps);

      if (right < startPos)
        continue;

      int leftFruit =
          std::lower_bound(positions.begin(), positions.end(), left) -
          positions.begin();
      int rightFruit =
          std::upper_bound(positions.begin(), positions.end(), right) -
          positions.begin() - 1;

      if (rightFruit >= leftFruit && leftFruit < n && rightFruit >= 0)
        mx = std::max(mx, prefixSum[rightFruit + 1] - prefixSum[leftFruit]);
    }

    for (int steps = 0; steps <= k; ++steps) {
      int right = startPos + steps;
      int left = startPos - (k - 2 * steps);

      if (left > startPos)
        continue;

      int rightFruit =
          std::upper_bound(positions.begin(), positions.end(), right) -
          positions.begin() - 1;
      int leftFruit =
          std::lower_bound(positions.begin(), positions.end(), left) -
          positions.begin();

      if (rightFruit >= leftFruit && leftFruit < n && rightFruit >= 0)
        mx = std::max(mx, prefixSum[rightFruit + 1] - prefixSum[leftFruit]);
    }

    return mx;
  }
};
