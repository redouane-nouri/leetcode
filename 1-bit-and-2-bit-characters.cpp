#include <vector>

class Solution {
public:
  bool isOneBitCharacter(std::vector<int> &bits) {
    bool hasOneBefore = false, isZero = false;
    for (int &bit : bits) {
      if (bit) {
        hasOneBefore = !hasOneBefore;
        isZero = false;
      } else {
        isZero = !hasOneBefore;
        hasOneBefore = false;
      }
    }

    return isZero;
  }
};
