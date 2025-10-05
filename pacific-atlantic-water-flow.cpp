#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  pacificAtlantic(std::vector<std::vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false)),
        atlantic(m, std::vector<bool>(n, false));
    int dirs[5] = {-1, 0, 1, 0, -1};

    auto dfs = [&heights, &dirs, m,
                n](auto &&dfs, int r, int c,
                   std::vector<std::vector<bool>> &ocean) -> void {
      ocean[r][c] = true;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dirs[i], nc = c + dirs[i + 1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && !ocean[nr][nc] &&
            heights[nr][nc] >= heights[r][c]) {
          dfs(dfs, nr, nc, ocean);
        }
      }
    };

    for (int r = 0; r < m; ++r) {
      dfs(dfs, r, 0, pacific);
      dfs(dfs, r, n - 1, atlantic);
    }

    for (int c = 0; c < n; ++c) {
      dfs(dfs, 0, c, pacific);
      dfs(dfs, m - 1, c, atlantic);
    }

    std::vector<std::vector<int>> res;
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (pacific[r][c] && atlantic[r][c]) {
          res.push_back({r, c});
        }
      }
    }

    return res;
  }
};
