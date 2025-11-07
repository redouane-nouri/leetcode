#include <algorithm>
#include <vector>

class Solution {
public:
  long long maxPower(std::vector<int> &stations, int r, int k) {
    const int n = stations.size();
    std::vector<long long> preSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      preSum[i + 1] = preSum[i] + stations[i];
    }

    std::vector<long long> powers(n);
    long long high = 1e10 + 1e9, low = high;

    for (int i = 0; i < n; ++i) {
      int left = std::max(0, i - r);
      int right = std::min(n, i + r + 1);
      powers[i] = preSum[right] - preSum[left];
      low = std::min(low, powers[i]);
    }

    long long maxPower = 0;

    auto canMax = [&n, &r, &powers](long long mx, long long k) mutable -> bool {
      std::vector<long long> added(n, 0);
      long long currAdd = 0;

      for (int i = 0; i < n; ++i) {
        if (i - r - 1 >= 0)
          currAdd -= added[i - r - 1];

        if (powers[i] + currAdd < mx) {
          long long needs = mx - (powers[i] + currAdd);
          if (k < needs) {
            return false;
          }
          k -= needs;
          int pos = std::min(n - 1, i + r);
          added[pos] = needs;
          currAdd += needs;
        }
      }

      return true;
    };

    while (low <= high) {
      long long md = low + (high - low) / 2;
      if (canMax(md, k)) {
        maxPower = md;
        low = md + 1;
      } else {
        high = md - 1;
      }
    }

    return maxPower;
  }
};
