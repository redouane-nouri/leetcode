/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MOD = 1'000'000'007;

public:
  vector<int> pathsWithMaxScore(vector<string> &board) {
    const int N = board.size();
    vector<int> prevSumDP(N + 1, -1), currSumDP(N + 1, -1);
    vector<int> prevCntDP(N + 1, 0), currCntDP(N + 1, 0);

    board[0][0] = '0';
    for (int i = N - 1; i >= 0; --i) {
      for (int j = N - 1; j >= 0; --j) {
        if (i == N - 1 && j == N - 1) {
          currSumDP[j] = 0, currCntDP[j] = 1;
          continue;
        }

        int prevBest = max({prevSumDP[j], prevSumDP[j + 1], currSumDP[j + 1]});

        if (prevBest == -1 || board[i][j] == 'X') {
          currSumDP[j] = -1, currCntDP[j] = 0;
          continue;
        }

        currSumDP[j] = (board[i][j] - '0' + prevBest);

        int cnt = 0;

        if (prevSumDP[j] == prevBest)
          cnt = (cnt + prevCntDP[j]) % MOD;

        if (prevSumDP[j + 1] == prevBest)
          cnt = (cnt + prevCntDP[j + 1]) % MOD;

        if (currSumDP[j + 1] == prevBest)
          cnt = (cnt + currCntDP[j + 1]) % MOD;

        currCntDP[j] = cnt;
      }

      swap(prevSumDP, currSumDP), swap(prevCntDP, currCntDP);
    }

    if (prevSumDP[0] == -1)
      return {0, 0};

    return {prevSumDP[0], prevCntDP[0]};
  }
};
