#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> n;

    for (int num : nums) {
      if (n.count(num)) {
        return true;
      }

      n.insert(num);
    }

    return false;
  }
};
