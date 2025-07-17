#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
    int val = 1;

    for (int start = 0; start < n / 2 + 1; ++start) {
      int end = n - start - 1;

      for (int col = start; col <= end; ++col)
        res[start][col] = val++;

      for (int row = start + 1; row <= end; ++row)
        res[row][end] = val++;

      for (int col = end - 1; col >= start; --col)
        res[end][col] = val++;

      for (int row = end - 1; row > start; --row)
        res[row][start] = val++;
    }

    return res;
  }
};
