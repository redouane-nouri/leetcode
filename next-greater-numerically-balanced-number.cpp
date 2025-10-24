#include <algorithm>
#include <climits>
#include <string>

class Solution {
  int n, res = INT_MAX, l, available = 0b1111111110;

  void dfs(int space) {
    if (space == 0) {
      std::string s;

      for (int i = 1; i <= 9; ++i) {
        if (!(available & (1 << i))) {
          s += std::string(i, '0' + i);
        }
      }

      std::sort(s.rbegin(), s.rend());
      if (std::stoi(s) <= n) {
        return;
      }

      std::sort(s.begin(), s.end());
      do {
        int v = std::stoi(s);
        if (v > n && v < res) {
          res = v;
        }
      } while (std::next_permutation(s.begin(), s.end()));

    } else {
      int d = __builtin_ctz(available);

      while (d <= 9 && d <= space) {
        if (available & (1 << d)) {
          available ^= (1 << d);
          dfs(space - d);
          available ^= (1 << d);
        }
        ++d;
      }
    }
  }

public:
  int nextBeautifulNumber(int n) {
    this->n = n;

    if (n < 10)
      l = 1;
    else if (n < 100)
      l = 2;
    else if (n < 1000)
      l = 3;
    else if (n < 10000)
      l = 4;
    else if (n < 100000)
      l = 5;
    else if (n < 1000000)
      l = 6;
    else
      l = 7;

    while (res == INT_MAX) {
      dfs(l);
      ++l;
    }

    return res;
  }
};
