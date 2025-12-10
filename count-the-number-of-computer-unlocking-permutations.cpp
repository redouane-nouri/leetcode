#include <vector>

class Solution {
public:
  int countPermutations(std::vector<int> &complexity) {
    const int N = complexity.size(), MOD = 1'000'000'007;
    int rootComp = complexity[0];
    long long ans = 1;

    for (int i = 1; i < N; ++i) {
      if (complexity[i] <= rootComp)
        return 0;

      ans = (ans * (N - i)) % MOD;
    }

    return ans;
  }
};
