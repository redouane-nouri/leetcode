#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  sortMatrix(std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    std::vector<int> d(n);

    for (int k = 0; k < (n << 2) + 1; ++k) {
      int i = k >= n ? k - n + 1 : 0, j = k < n - 1 ? n - k - 1 : 0, l = 0;

      while (i < n && j < n)
        d[l++] = grid[i++][j++];

      std::sort(d.begin(), d.begin() + l);

      --i;
      --j;
      --l;
      int o = 0;

      if (k < n - 1)
        while (i >= 0 && j >= 0 && l >= 0)
          grid[i--][j--] = d[l--];
      else
        while (i >= 0 && j >= 0 && o <= l)
          grid[i--][j--] = d[o++];
    }

    return grid;
  }
};
