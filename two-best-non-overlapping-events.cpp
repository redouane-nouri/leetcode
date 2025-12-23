#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int maxTwoEvents(std::vector<std::vector<int>> &events) {
    std::sort(events.begin(), events.end());

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;

    int ans = 0, bestPrevious = 0;
    for (auto &e : events) {
      while (!pq.empty() && e[0] > pq.top().first) {
        bestPrevious = std::max(bestPrevious, pq.top().second);
        pq.pop();
      }

      ans = std::max(ans, e[2] + bestPrevious);
      pq.push({e[1], e[2]});
    }

    return ans;
  }
};
