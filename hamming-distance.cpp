class Solution {
public:
  int hammingDistance(int x, int y) {
    int res = 0, xorRes = x ^ y;

    while (xorRes) {
      xorRes &= xorRes - 1;
      ++res;
    }

    return res;
  }
};
