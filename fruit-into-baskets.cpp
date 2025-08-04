#include <vector>

class Solution {
public:
  int totalFruit(std::vector<int> &fruits) {
    int type1 = -1, type2 = -1, lastType = -1, mx = 0, currMx = 0,
        lastTypeFreq = 0, sz = fruits.size();

    for (int i = 0; i < sz; ++i) {
      if (fruits[i] == type1 || fruits[i] == type2) {
        ++currMx;
      } else {
        currMx = lastTypeFreq + 1;
      }

      if (fruits[i] == lastType) {
        ++lastTypeFreq;
      } else {
        type1 = type2;
        type2 = fruits[i];
        lastType = fruits[i];
        lastTypeFreq = 1;
      }

      if (currMx > mx)
        mx = currMx;
    }

    return mx;
  }
};
