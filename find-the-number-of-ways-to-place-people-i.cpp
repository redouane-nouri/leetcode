#include <algorithm>
#include <vector>

class Solution {
public:
  int numberOfPairs(std::vector<std::vector<int>> &points) {
    std::sort(points.begin(), points.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
              });

    int res = 0, n = points.size();

    for (int i = 0; i < n; ++i) {
      int &y1 = points[i][1], ly = -1;

      for (int j = i + 1; j < n; ++j) {
        int &y2 = points[j][1];

        if (y1 >= y2 && ly < y2) {
          ++res;
          ly = y2;
        }
      }
    }

    return res;
  }
};
