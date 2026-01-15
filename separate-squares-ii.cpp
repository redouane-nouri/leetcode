#include <algorithm>
#include <array>
#include <set>
#include <vector>

class SegmentTree {
  std::vector<int> xs, count, covered;
  int n;

  void modify(int x, int xr, int op, int left, int right, int i) {
    if (xs[right + 1] <= x || xs[left] >= xr) {
      return;
    }

    if (x <= xs[left] && xs[right + 1] <= xr) {
      count[i] += op;
    } else {
      int mid = (left + right) / 2;
      modify(x, xr, op, left, mid, (i << 1) + 1);
      modify(x, xr, op, mid + 1, right, (i << 1) + 2);
    }

    if (count[i] > 0) {
      covered[i] = xs[right + 1] - xs[left];
    } else {
      if (left == right) {
        covered[i] = 0;
      } else {
        covered[i] = covered[(i << 1) + 1] + covered[(i << 1) + 2];
      }
    }
  }

public:
  SegmentTree(std::vector<int> xs_) : xs(xs_) {
    n = xs.size() - 1;
    count.resize(n << 2, 0);
    covered.resize(n << 2, 0);
  }

  int query() { return covered[0]; }

  void update(int x, int xr, int val) { modify(x, xr, val, 0, n - 1, 0); }
};

class Solution {
public:
  double separateSquares(std::vector<std::vector<int>> &squares) {
    std::vector<std::array<int, 4>> events;
    events.reserve(squares.size() * 2);
    std::set<int> xs;

    for (auto &s : squares) {
      int &x = s[0], &y = s[1], &l = s[2], xr = x + l;
      events.push_back({y, 1, x, xr});
      events.push_back({y + l, -1, x, xr});
      xs.insert(x);
      xs.insert(xr);
    }

    std::sort(events.begin(), events.end());
    SegmentTree segTree({xs.begin(), xs.end()});

    std::vector<double> areas;
    std::vector<int> widths;
    double totalArea = 0.0;
    int prevY = events[0][0];

    for (auto &[y, op, x, xr] : events) {
      totalArea += 1LL * segTree.query() * (y - prevY);
      segTree.update(x, xr, op);
      areas.push_back(totalArea);
      widths.push_back(segTree.query());
      prevY = y;
    }

    long long upperArea = static_cast<long long>(totalArea + 1) / 2;
    int i = std::lower_bound(areas.begin(), areas.end(), upperArea) -
            areas.begin() - 1;
    return events[i][0] + (totalArea - (2.0 * areas[i])) / (2.0 * widths[i]);
  }
};
