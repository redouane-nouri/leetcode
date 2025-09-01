#include <queue>
#include <utility>
#include <vector>

class Solution {
  static double getGain(const int &p, const int &t) {
    return static_cast<double>((p + 1)) / (t + 1) - static_cast<double>(p) / t;
  }

  static bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return getGain(a.first, a.second) < getGain(b.first, b.second);
  };

public:
  double maxAverageRatio(std::vector<std::vector<int>> &classes,
                         int extraStudents) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        bool (*)(const std::pair<int, int> &,
                                 const std::pair<int, int> &)>
        pq(cmp);

    int n = classes.size();

    for (int i = 0; i < n; ++i)
      pq.push({classes[i][0], classes[i][1]});

    while (extraStudents--) {
      std::pair<int, int> t = pq.top();
      pq.pop();
      pq.push({t.first + 1, t.second + 1});
    }

    double res = 0;
    while (!pq.empty()) {
      std::pair<int, int> t = pq.top();
      pq.pop();
      res += static_cast<double>(t.first) / t.second;
    }

    return res / n;
  }
};
