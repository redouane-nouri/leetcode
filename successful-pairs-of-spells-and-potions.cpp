#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> successfulPairs(std::vector<int> &spells,
                                   std::vector<int> &potions,
                                   long long success) {
    std::sort(potions.begin(), potions.end());
    std::vector<int> res;

    for (int &s : spells) {
      std::vector<int>::iterator it = std::lower_bound(
          potions.begin(), potions.end(), (success + s - 1) / s);
      res.push_back(potions.end() - it);
    }

    return res;
  }
};
