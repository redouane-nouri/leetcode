#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int maximizeSquareArea(int m, int n, std::vector<int> &hFences,
                         std::vector<int> &vFences) {
    hFences.push_back(1);
    hFences.push_back(m);
    vFences.push_back(1);
    vFences.push_back(n);
    std::sort(hFences.begin(), hFences.end());
    std::sort(vFences.begin(), vFences.end());

    std::unordered_set<int> hEdgesLength;
    const int HN = hFences.size(), VN = vFences.size();

    for (int i = 1; i < HN; ++i)
      for (int j = 0; j < i; ++j)
        hEdgesLength.insert(hFences[i] - hFences[j]);

    int maxSide = 0;

    for (int i = 0; i < VN; ++i) {
      for (int j = 0; j < i; ++j) {
        int side = vFences[i] - vFences[j];

        if (hEdgesLength.count(side))
          maxSide = std::max(maxSide, side);
      }
    }

    if (maxSide)
      return (1LL * maxSide * maxSide) % 1'000'000'007;

    return -1;
  }
};
