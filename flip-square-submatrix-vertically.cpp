/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y,
                                       int k) {
    int xEnd = x + k - 1;

    while (x < xEnd) {
      for (int j = y; j < y + k; ++j) {
        int &a = grid[x][j], &b = grid[xEnd][j];
        a = a ^ b, b = a ^ b, a = a ^ b;
      }

      ++x, --xEnd;
    }

    return grid;
  }
};
