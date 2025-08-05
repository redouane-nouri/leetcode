#include <string>
#include <vector>

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    int m = board.size(), n = board[0].size(), wordSize = word.size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (search(board, word, m, n, 0, wordSize, i, j))
          return true;
      }
    }

    return false;
  }

private:
  bool search(std::vector<std::vector<char>> &board, std::string &word, int m,
              int n, int matchCount, int wordSize, int i, int j) {
    if (matchCount == wordSize)
      return true;

    if (i < 0 || j < 0 || i >= m || j >= n)
      return false;

    if (board[i][j] != word[matchCount])
      return false;

    char tmp = board[i][j];
    board[i][j] = ' ';

    bool res = search(board, word, m, n, matchCount + 1, wordSize, i + 1, j) ||
               search(board, word, m, n, matchCount + 1, wordSize, i - 1, j) ||
               search(board, word, m, n, matchCount + 1, wordSize, i, j + 1) ||
               search(board, word, m, n, matchCount + 1, wordSize, i, j - 1);

    board[i][j] = tmp;

    return res;
  }
};
