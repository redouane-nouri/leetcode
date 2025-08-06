#include <algorithm>
#include <vector>

class Solution {
  std::vector<int> segmentTree;

  void constructSegmentTreeRMQ(std::vector<int> &baskets, int l, int r, int i) {
    if (l == r) {
      segmentTree[i] = baskets[l];
      return;
    }

    int m = l + (r - l) / 2;

    constructSegmentTreeRMQ(baskets, l, m, i * 2 + 1);
    constructSegmentTreeRMQ(baskets, m + 1, r, i * 2 + 2);

    segmentTree[i] = std::max(segmentTree[i * 2 + 1], segmentTree[i * 2 + 2]);
  }

  bool isFitable(int fruit, int l, int r, int i) {
    if (segmentTree[i] < fruit)
      return false;

    if (l == r) {
      segmentTree[i] = 0;
      return true;
    }

    bool isFound;
    int m = l + (r - l) / 2;

    if (segmentTree[i * 2 + 1] >= fruit)
      isFound = isFitable(fruit, l, m, i * 2 + 1);
    else
      isFound = isFitable(fruit, m + 1, r, i * 2 + 2);

    segmentTree[i] = std::max(segmentTree[i * 2 + 1], segmentTree[i * 2 + 2]);

    return isFound;
  }

public:
  int numOfUnplacedFruits(std::vector<int> &fruits, std::vector<int> &baskets) {
    int n = baskets.size(), res = 0;
    segmentTree = std::vector<int>(4 * n);

    constructSegmentTreeRMQ(baskets, 0, n - 1, 0);

    for (int i = 0; i < n; ++i) {
      if (!isFitable(fruits[i], 0, n - 1, 0))
        ++res;
    }

    return res;
  }
};
