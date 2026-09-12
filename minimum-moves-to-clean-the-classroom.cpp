/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

  struct Cell {
    int x, y, enrg, stps;
    bitset<10> mask;
  };

public:
  int minMoves(vector<string> &classroom, int energy) {
    const int M = classroom.size(), N = classroom[0].size();
    int sx, sy, cnt = 0;
    vector masks(M, vector<bitset<10>>(N));

    for (int x = 0; x < M; ++x)
      for (int y = 0; y < N; ++y)
        if (classroom[x][y] == 'L')
          masks[x][y].set(cnt++);
        else if (classroom[x][y] == 'S')
          sx = x, sy = y;

    vector memo(M, vector(N, vector<int>(1 << cnt, -1)));
    memo[sx][sy][0] = energy;
    queue<Cell> q;
    q.push({sx, sy, energy, 0, 0});

    while (!q.empty()) {
      Cell cell = q.front();
      q.pop();

      if (cell.mask.count() == cnt)
        return cell.stps;

      if (cell.enrg == 0)
        continue;

      for (int d = 0; d < 4; ++d) {
        int nx = cell.x + dx[d], ny = cell.y + dy[d];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N || classroom[nx][ny] == 'X')
          continue;

        bitset<10> nmask = cell.mask | masks[nx][ny];
        int nenrg = classroom[nx][ny] == 'R' ? energy : cell.enrg - 1;

        if (nenrg > memo[nx][ny][nmask.to_ulong()]) {
          memo[nx][ny][nmask.to_ulong()] = nenrg;
          q.push({nx, ny, nenrg, cell.stps + 1, nmask});
        }
      }
    }

    return -1;
  }
};
