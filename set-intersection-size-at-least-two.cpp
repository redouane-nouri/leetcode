#include <algorithm>
#include <vector>

class Solution {
public:
  int intersectionSizeTwo(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const auto &a, const auto &b) {
                return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
              });
    int size = 0, lowerBound = -1, upperBound = -1;

    for (auto &interval : intervals) {
      int &start = interval[0], &end = interval[1];

      if (start > upperBound) {
        size += 2;
        lowerBound = end - 1;
        upperBound = end;
      } else if (start > lowerBound) {
        ++size;
        lowerBound = upperBound;
        upperBound = end;
      }
    }

    return size;
  }
};
