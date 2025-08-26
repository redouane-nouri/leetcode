#include <vector>

class Solution {
public:
  int areaOfMaxDiagonal(std::vector<std::vector<int>> &dimensions) {
    int m = dimensions.size(), area = 0, maxDiagSq = 0;

    for (int i = 0; i < m; ++i) {
      int diagSq = dimensions[i][0] * dimensions[i][0] +
                   dimensions[i][1] * dimensions[i][1],
          currArea = dimensions[i][0] * dimensions[i][1];

      if (diagSq > maxDiagSq || (diagSq == maxDiagSq && currArea > area)) {
        maxDiagSq = diagSq;
        area = currArea;
      }
    }

    return area;
  }
};
