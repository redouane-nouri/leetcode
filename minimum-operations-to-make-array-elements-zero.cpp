#include <vector>

class Solution {
  long long calcOps(int l, int r) {
    long long b = 1, o = 1;

    while (b << 2 < l) {
      b <<= 2;
      ++o;
    }

    long long ops = 0;

    if (l > b)
      ops = -(l - b) * o;

    while (b <= r) {
      ops += o * ((b << 2) - b);
      b <<= 2;
      ++o;
    }

    if (r != b - 1)
      ops -= (o - 1) * (b - r - 1);

    return (ops + 1) / 2;
  }

public:
  long long minOperations(std::vector<std::vector<int>> &queries) {
    int n = queries.size();
    long long res = 0;

    for (int i = 0; i < n; ++i)
      res += calcOps(queries[i][0], queries[i][1]);

    return res;
  }
};
