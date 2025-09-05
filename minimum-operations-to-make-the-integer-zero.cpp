class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    for (int k = 1; k <= 60; ++k) {
      long long r = num1 - static_cast<long long>(num2) * k;

      if (r < k)
        return -1;

      if (k >= __builtin_popcountll(r))
        return k;
    }
    return -1;
  }
};
