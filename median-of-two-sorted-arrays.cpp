#include <climits>
#include <utility>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    int sz1 = nums1.size(), sz2 = nums2.size();

    if (sz1 > sz2) {
      std::swap(nums1, nums2);
      std::swap(sz1, sz2);
    }

    int l = 0, r = sz1;

    while (l <= r) {
      int i = (l + r) / 2;
      int j = (sz1 + sz2 + 1) / 2 - i;

      int maxL1 = (i == 0) ? INT_MIN : nums1[i - 1];
      int minR1 = (i == sz1) ? INT_MAX : nums1[i];
      int maxL2 = (j == 0) ? INT_MIN : nums2[j - 1];
      int minR2 = (j == sz2) ? INT_MAX : nums2[j];

      if (maxL1 <= minR2 && maxL2 <= minR1) {
        if ((sz1 + sz2) % 2 != 0)
          return std::max(maxL1, maxL2);
        else
          return (std::max(maxL1, maxL2) + std::min(minR1, minR2)) / 2.0;
      } else if (maxL1 > minR2) {
        r = i - 1;
      } else {
        l = i + 1;
      }
    }

    return 0.0;
  }
};
