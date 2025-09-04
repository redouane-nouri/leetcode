#include <cstdlib>

class Solution {
public:
  int findClosest(int x, int y, int z) {
    return (std::abs(z - x) < std::abs(z - y))
               ? 1
               : (std::abs(z - x) > std::abs(z - y) ? 2 : 0);
  }
};
