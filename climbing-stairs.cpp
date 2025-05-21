class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;

    int n_2 = 1, n_1 = 2, current;

    for (int i = 3; i <= n; ++i) {
      current = n_1 + n_2;
      n_2 = n_1;
      n_1 = current;
    }

    return current;
  }
};
