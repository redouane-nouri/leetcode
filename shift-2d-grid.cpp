/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int ROWS = grid.size(), COLS = grid[0].size(), TOTAL_CELLS = ROWS * COLS;
    k %= TOTAL_CELLS;

    vector<vector<int>> result(ROWS, vector<int>(COLS));

    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        int oldIndex = r * COLS + c, newIndex = (oldIndex + k) % TOTAL_CELLS;
        int newRow = newIndex / COLS, newCol = newIndex % COLS;

        result[newRow][newCol] = grid[r][c];
      }
    }

    return result;
  }
};
