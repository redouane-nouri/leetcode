#include <string>
#include <vector>

class Solution {
public:
  int bestClosingTime(std::string customers) {
    const int N = customers.size();
    std::vector<int> prefixY(N + 1);
    prefixY[0] = 0;

    for (int i = 0; i < N; ++i)
      prefixY[i + 1] = prefixY[i] + (customers[i] == 'Y' ? 1 : 0);

    int idx = 0, mn = prefixY[N] - prefixY[0];

    for (int i = 1; i <= N; ++i) {
      int tmpMn = prefixY[N] - prefixY[i] + i - prefixY[i];

      if (tmpMn < mn) {
        mn = tmpMn;
        idx = i;
      }
    }

    return idx;
  }
};
