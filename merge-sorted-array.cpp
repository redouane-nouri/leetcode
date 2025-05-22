#include <algorithm>
#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int m_i = m - 1, n_i = n - 1, j = m + n - 1;

    while (m_i >= 0 && n_i >= 0) {
      if (nums1[m_i] > nums2[n_i]) {
        nums1[j] = nums1[m_i--];
      } else {
        nums1[j] = nums2[n_i--];
      }

      --j;
    }

    while (n_i >= 0) {
      nums1[j--] = nums2[n_i--];
    }
  }
};
