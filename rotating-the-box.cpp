/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid) {
    const int M = boxGrid.size(), N = boxGrid[0].size();
    vector<vector<char>> ans(N, vector<char>(M, '.'));

    for (int i = 0; i < M; ++i) {
      int k = N - 1;

      for (int j = N - 1; j >= 0; --j)
        switch (boxGrid[i][j]) {
        case '#':
          ans[k][M - 1 - i] = '#', --k;
          break;
        case '*':
          ans[j][M - 1 - i] = '*', k = j - 1;
        }
    }

    return ans;
  }
};
