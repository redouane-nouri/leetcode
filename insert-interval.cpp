#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                       std::vector<int> &newInterval) {
    std::vector<std::vector<int>> res;
    int i = 0, sz = intervals.size();

    while (i < sz && intervals[i][1] < newInterval[0])
      res.push_back(intervals[i++]);

    while (i < sz && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = std::min(intervals[i][0], newInterval[0]);
      newInterval[1] = std::max(intervals[i++][1], newInterval[1]);
    }

    res.push_back(newInterval);

    while (i < sz)
      res.push_back(intervals[i++]);

    return res;
  }
};
