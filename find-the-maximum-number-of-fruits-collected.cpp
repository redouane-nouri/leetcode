#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

class Solution {
  std::vector<std::vector<int>> memo;
  int n;

  int search(std::vector<std::vector<int>> &fruits,
             std::vector<std::pair<int, int>> &moves, int movesCount, int i,
             int j) {
    if (i == n - 1 && j == n - 1)
      return movesCount == 0 ? 0 : INT_MAX;

    if (memo[i][j] != -1)
      return memo[i][j];

    if (movesCount == 0 || i == j)
      return INT_MAX;

    int count = -1;

    for (int k = 0; k < 3; ++k) {
      int newI = moves[k].first + i, newJ = moves[k].second + j;

      if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
        int res = search(fruits, moves, movesCount - 1, newI, newJ);

        if (res != INT_MAX)
          count = std::max(count, res);
      }
    }

    return memo[i][j] = (count == -1 ? INT_MAX : count + fruits[i][j]);
  }

public:
  int maxCollectedFruits(std::vector<std::vector<int>> &fruits) {
    n = fruits.size();
    memo = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

    int res = 0;

    for (int i = 0; i < n; ++i)
      res += fruits[i][i];

    std::vector<std::pair<int, int>> moves = {{1, -1}, {1, 0}, {1, 1}};
    res += search(fruits, moves, n - 1, 0, n - 1);

    for (std::vector<int> &row : memo)
      std::fill(row.begin(), row.end(), -1);

    moves = {{-1, 1}, {0, 1}, {1, 1}};
    res += search(fruits, moves, n - 1, n - 1, 0);

    return res;
  }
};
