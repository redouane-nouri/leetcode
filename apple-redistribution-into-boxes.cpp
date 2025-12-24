#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  int minimumBoxes(std::vector<int> &apple, std::vector<int> &capacity) {
    int apples = std::accumulate(apple.begin(), apple.end(), 0);
    std::sort(capacity.begin(), capacity.end(),
              [](const auto &a, const auto &b) { return a > b; });

    int i = 0;
    while (apples > 0)
      apples -= capacity[i++];

    return i;
  }
};
