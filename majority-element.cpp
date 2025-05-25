#include <vector>

class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    // Boyer-Moore majority vote algo
    int candidate, count = 0;

    for (int nbr : nums) {
      if (count == 0) {
        candidate = nbr;
      }

      candidate != nbr ? --count : ++count;
    }

    return candidate;
  }
};
