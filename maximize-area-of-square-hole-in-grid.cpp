#include <algorithm>
#include <vector>

class Solution {
public:
  int maximizeSquareHoleArea(int n, int m, std::vector<int> &hBars,
                             std::vector<int> &vBars) {
    std::sort(hBars.begin(), hBars.end());
    std::sort(vBars.begin(), vBars.end());

    const int HN = hBars.size(), VN = vBars.size();
    int hmx = 1, currHmx = 1, vmx = 1, currVmx = 1;

    for (int i = 1; i < HN; ++i) {
      if (hBars[i] == hBars[i - 1] + 1)
        ++currHmx;
      else
        currHmx = 1;

      hmx = std::max(hmx, currHmx);
    }

    for (int i = 1; i < VN; ++i) {
      if (vBars[i] == vBars[i - 1] + 1)
        ++currVmx;
      else
        currVmx = 1;

      vmx = std::max(vmx, currVmx);
    }

    int l = std::min(hmx, vmx) + 1;
    return l * l;
  }
};
