#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int minCost(std::string colors, std::vector<int> &neededTime) {
    int n = colors.size(), res = 0, mx = neededTime[0];

    for (int i = 1; i < n; ++i) {
      if (colors[i - 1] == colors[i]) {
        res += std::min(mx, neededTime[i]);
        mx = std::max(mx, neededTime[i]);
      } else {
        mx = neededTime[i];
      }
    }
    return res;
  }
};
