#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> intersection(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    if (set1.size() > set2.size())
      std::swap(set1, set2);

    std::vector<int> res;

    for (int num : set1) {
      if (set2.count(num))
        res.push_back(num);
    }

    return res;
  }
};
