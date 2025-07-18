
#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    std::vector<int> res;
    int n1 = nums1.size(), n2 = nums2.size(), i = 0, j = 0;

    while (i < n1 && j < n2) {
      if (nums1[i] == nums2[j]) {
        res.push_back(nums1[i++]);
        j++;
      } else if (nums1[i] > nums2[j]) {
        ++j;
      } else {
        ++i;
      }
    }

    return res;
  }
};
