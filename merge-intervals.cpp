#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> res;
    int sz = intervals.size();

    std::sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);

    for (int i = 1; i < sz; ++i) {
      std::vector<int> &back = res.back();

      if (intervals[i][0] <= back[1])
        back[1] = std::max(intervals[i][1], back[1]);
      else
        res.push_back(intervals[i]);
    }

    return res;
  }
};
