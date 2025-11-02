#include <vector>

class Solution {
public:
  int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards,
                     std::vector<std::vector<int>> &walls) {
    std::vector<std::vector<char>> marked(m, std::vector<char>(n, ' '));

    for (std::vector<int> &w : walls) {
      marked[w[0]][w[1]] = 'W';
    }

    for (std::vector<int> &g : guards) {
      marked[g[0]][g[1]] = 'G';
    }

    int dir[] = {0, 1, 0, -1, 0};
    for (std::vector<int> &g : guards) {
      int i = g[0], j = g[1];

      for (int d = 0; d < 4; ++d) {
        int x = i + dir[d], y = j + dir[d + 1];

        while (x >= 0 && y >= 0 && x < m && y < n) {
          if (marked[x][y] == 'G' || marked[x][y] == 'W') {
            break;
          }

          marked[x][y] = '*';
          x += dir[d];
          y += dir[d + 1];
        }
      }
    }

    int res = m * n;
    for (std::vector<char> &row : marked) {
      for (char &c : row) {
        switch (c) {
        case 'G':
        case 'W':
        case '*':
          --res;
        }
      }
    }

    return res;
  }
};
