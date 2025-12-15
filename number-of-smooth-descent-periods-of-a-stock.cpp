#include <vector>

class Solution {
public:
  long long getDescentPeriods(std::vector<int> &prices) {
    const int N = prices.size();
    long long ans = 1, l = 1;

    for (int i = 1; i < N; ++i) {
      prices[i] + 1 == prices[i - 1] ? ++l : l = 1;
      ans += l;
    }

    return ans;
  }
};
