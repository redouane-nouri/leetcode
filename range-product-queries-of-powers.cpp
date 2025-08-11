#include <vector>

class Solution {
  const int MOD = 1'000'000'007;

  // Fermat's little theorem
  int inverse(long long base) {
    long long res = 1;
    unsigned int pow = MOD - 2;

    while (pow) {
      if (pow & 1)
        res = (res * base) % MOD;

      base = (base * base) % MOD;
      pow >>= 1;
    }

    return static_cast<int>(res);
  }

public:
  std::vector<int> productQueries(int n,
                                  std::vector<std::vector<int>> &queries) {

    unsigned int powerOf2 = 1U, sz = queries.size();
    std::vector<int> powers, answers(sz);

    while (powerOf2 <= n) {
      if (n & powerOf2)
        powers.push_back(powerOf2);

      powerOf2 <<= 1;
    }

    int m = powers.size();
    std::vector<int> prefixProd(m);
    prefixProd[0] = powers[0];

    for (int i = 1; i < m; ++i)
      prefixProd[i] =
          static_cast<int>((1LL * prefixProd[i - 1] * powers[i]) % MOD);

    for (int i = 0; i < sz; ++i)
      answers[i] =
          queries[i][0] == 0
              ? prefixProd[queries[i][1]]
              : static_cast<int>((1LL * prefixProd[queries[i][1]] *
                                  inverse(prefixProd[queries[i][0] - 1])) %
                                 MOD);

    return answers;
  }
};
