#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  double separateSquares(std::vector<std::vector<int>> &squares) {
    int minY = 2e9, maxY = 0;

    for (const auto &s : squares) {
      minY = std::min(minY, s[1]);
      maxY = std::max(maxY, s[1] + s[2]);
    }

    const auto getBelowAndAboveAreas =
        [&squares](double y) -> std::pair<double, double> {
      double below = 0.0, above = 0.0;

      for (const auto &s : squares) {
        double sy = s[1], sl = s[2];
        below += sl * std::min(sl, std::max(y - sy, 0.0));
        above += sl * std::min(sl, std::max(sy + sl - y, 0.0));
      }

      return {below, above};
    };

    double l = minY, r = maxY;

    while (r - l > 1e-6) {
      const double m = (l + r) / 2.0;
      auto [below, above] = getBelowAndAboveAreas(m);

      if (below < above)
        l = m;
      else
        r = m;
    }

    return (r + l) / 2.0;
  }
};
