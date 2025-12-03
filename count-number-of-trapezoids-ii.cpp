#include <cmath>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>

struct pair_hash {
  std::size_t operator()(const std::pair<int, int> &p) const noexcept {
    return (std::hash<int>()(p.first) << 1) ^ std::hash<int>()(p.second);
  }
};

class Solution {
public:
  int countTrapezoids(std::vector<std::vector<int>> &points) {

    auto slope = [](const std::vector<int> &p1,
                    const std::vector<int> &p2) -> std::pair<int, int> {
      int dx = p2[0] - p1[0];
      int dy = p2[1] - p1[1];

      if (dx == 0)
        return {1, 0};

      if (dy == 0)
        return {0, 1};

      int g = std::gcd(dx, dy);
      dx /= g;
      dy /= g;

      if (dx < 0) {
        dx = -dx;
        dy = -dy;
      }

      return {dy, dx};
    };

    auto intercept = [](const std::vector<int> &p1,
                        const std::vector<int> &p2) -> std::pair<int, int> {
      int dx = p2[0] - p1[0];
      int dy = p2[1] - p1[1];

      if (dx == 0)
        return {p1[0], 1};

      int num = p1[1] * dx - dy * p1[0];

      int g = std::gcd(num, dx);
      dx /= g;
      num /= g;

      if (dx < 0) {
        dx = -dx;
        num = -num;
      }

      return {num, dx};
    };

    const int N = points.size();

    std::unordered_map<std::pair<int, int>,
                       std::unordered_map<std::pair<int, int>, int, pair_hash>,
                       pair_hash>
        slopeToInterceptCount;

    std::unordered_map<std::pair<int, int>,
                       std::unordered_map<std::pair<int, int>, int, pair_hash>,
                       pair_hash>
        scaledMidToSlopeCount;

    for (int i = 0; i < N - 1; ++i) {
      for (int j = i + 1; j < N; ++j) {
        auto s = slope(points[i], points[j]);
        ++slopeToInterceptCount[s][intercept(points[i], points[j])];

        std::pair<int, int> mid = {points[i][0] + points[j][0],
                                   points[i][1] + points[j][1]};
        ++scaledMidToSlopeCount[mid][s];
      }
    }

    int ans = 0;
    for (auto &slopeEntry : slopeToInterceptCount) {
      int pref = 0;
      for (auto &interceptEntry : slopeEntry.second) {
        int cnt = interceptEntry.second;
        ans += pref * cnt;
        pref += cnt;
      }
    }

    for (auto &scaledMidEntry : scaledMidToSlopeCount) {
      int pref = 0;
      for (auto &sEntry : scaledMidEntry.second) {
        int cnt = sEntry.second;
        ans -= pref * cnt;
        pref += cnt;
      }
    }

    return ans;
  }
};
