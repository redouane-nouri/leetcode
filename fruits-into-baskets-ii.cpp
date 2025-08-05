#include <vector>

class Solution {
public:
  int numOfUnplacedFruits(std::vector<int> &fruits, std::vector<int> &baskets) {
    int count = 0;

    for (int i = 0; i < fruits.size(); ++i) {
      int j = 0;

      while (j < baskets.size()) {
        if (fruits[i] <= baskets[j]) {
          baskets[j] = -1;
          ++count;
          break;
        }

        ++j;
      }
    }

    return fruits.size() - count;
  }
};
