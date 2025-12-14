#include <string>
#include <vector>

class Solution {
public:
  int numberOfWays(std::string corridor) {
    std::vector<int> seats;
    const int N = corridor.size(), MOD = 1'000'000'007;

    for (int i = 0; i < N; ++i)
      if (corridor[i] == 'S')
        seats.push_back(i);

    const int SN = seats.size();

    if (SN < 2 || SN % 2 == 1)
      return 0;

    long long ans = 1;

    for (int i = 2; i < SN; i += 2)
      ans = (ans * (seats[i] - seats[i - 1])) % MOD;

    return ans;
  }
};
