#include <vector>

class Solution {
  const long long mod = 1'000'000'007;

public:
  long long magicalSum(int m, int k, std::vector<int> &nums) {
    auto mul = [](long long x, long long y, long long mod) -> long long {
      long long res = 1, curr = x % mod;

      while (y) {
        if (y & 1) {
          res = res * curr % mod;
        }

        curr = curr * curr % mod;
        y >>= 1;
      }

      return res;
    };

    std::vector<long long> fac(m + 1);
    fac[0] = 1;
    for (int i = 1; i <= m; ++i) {
      fac[i] = fac[i - 1] * i % mod;
    }

    std::vector<long long> invFac(m + 1);
    invFac[0] = invFac[1] = 1;
    for (int i = 2; i <= m; ++i) {
      invFac[i] = mul(i, mod - 2, mod);
    }

    for (int i = 2; i <= m; ++i) {
      invFac[i] = invFac[i - 1] * invFac[i] % mod;
    }

    long long n = nums.size();
    std::vector<std::vector<long long>> powers(n,
                                               std::vector<long long>(m + 1));
    for (int i = 0; i < n; ++i) {
      powers[i][0] = 1;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= m; ++j) {
        powers[i][j] = powers[i][j - 1] * nums[i] % mod;
      }
    }

    std::vector<std::vector<std::vector<std::vector<long long>>>> dp(
        n, std::vector(m + 1, std::vector(m * 2 + 1, std::vector(k + 1, 0LL))));

    for (int j = 0; j <= m; j++) {
      dp[0][j][j][0] = powers[0][j] * invFac[j] % mod;
    }

    for (int i = 0; i + 1 < n; i++) {
      for (int j = 0; j <= m; j++) {
        for (int p = 0; p <= m * 2; p++) {
          for (int q = 0; q <= k; q++) {
            long long q2 = p % 2 + q;
            if (q2 > k) {
              break;
            }
            for (int r = 0; r + j <= m; r++) {
              long long p2 = p / 2 + r;
              dp[i + 1][j + r][p2][q2] =
                  (dp[i + 1][j + r][p2][q2] +
                   dp[i][j][p][q] * powers[i + 1][r] % mod * invFac[r] % mod) %
                  mod;
            }
          }
        }
      }
    }

    long long res = 0;
    for (int p = 0; p <= m * 2; p++) {
      for (int q = 0; q <= k; q++) {
        if (__builtin_popcount(p) + q == k) {
          res = (res + dp[n - 1][m][p][q] * fac[m] % mod) % mod;
        }
      }
    }

    return res;
  }
};
