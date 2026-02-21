class Solution {
  bool isPrime(const int &x) {
    if (x <= 1)
      return false;

    if (x == 2 || x == 3)
      return true;

    if (x % 2 == 0 || x % 3 == 0)
      return false;

    for (int i = 5; i * i <= x; i += 6)
      if (x % i == 0 || x % (i + 2) == 0)
        return false;

    return true;
  }

public:
  int countPrimeSetBits(int left, int right) {
    int ans = 0;

    for (int num = left; num <= right; ++num)
      if (isPrime(__builtin_popcount(num)))
        ++ans;

    return ans;
  }
};
