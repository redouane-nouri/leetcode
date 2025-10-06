#include <algorithm>
#include <array>
#include <functional>
#include <queue>
#include <vector>

class Solution {
public:
  int swimInWater(std::vector<std::vector<int>> &grid) {
    int ni = grid.size() - 1, dirs[5] = {-1, 0, 1, 0, -1};
    std::vector<std::vector<bool>> v(ni + 1, std::vector(ni + 1, false));
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
                        std::greater<std::array<int, 3>>>
        pq;

    pq.push({grid[0][0], 0, 0});
    v[0][0] = true;

    while (true) {
      std::array<int, 3> t = pq.top();
      pq.pop();

      if (t[1] == ni && t[2] == ni) {
        return t[0];
      }

      for (int i = 0; i < 4; ++i) {
        int nx = t[1] + dirs[i], ny = t[2] + dirs[i + 1];
        if (nx >= 0 && nx <= ni && ny >= 0 && ny <= ni && !v[nx][ny]) {
          v[nx][ny] = true;
          pq.push({std::max(t[0], grid[nx][ny]), nx, ny});
        }
      }
    }

    return -1;
  }
};
