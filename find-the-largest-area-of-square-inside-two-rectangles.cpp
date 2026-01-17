#include <algorithm>
#include <vector>

class Solution {
public:
  long long largestSquareArea(std::vector<std::vector<int>> &bottomLeft,
                              std::vector<std::vector<int>> &topRight) {
    const int N = bottomLeft.size();
    int maxSide = 0;

    for (int i = 0; i < N; ++i) {
      int &bx1 = bottomLeft[i][0], &by1 = bottomLeft[i][1],
          &tx1 = topRight[i][0], &ty1 = topRight[i][1];

      for (int j = i + 1; j < N; ++j) {
        int bx = std::max(bx1, bottomLeft[j][0]);
        int by = std::max(by1, bottomLeft[j][1]);
        int tx = std::min(tx1, topRight[j][0]);
        int ty = std::min(ty1, topRight[j][1]);

        if (bx < tx && by < ty) {
          int side = std::min(tx - bx, ty - by);
          maxSide = std::max(maxSide, side);
        }
      }
    }

    return 1LL * maxSide * maxSide;
  }
};
