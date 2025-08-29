class Solution {
public:
  long long flowerGame(int n, int m) {
    return 1LL * (m / 2) * ((n + 1) / 2) + 1LL * (n / 2) * ((m + 1) / 2);
  }
};
