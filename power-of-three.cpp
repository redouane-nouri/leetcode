class Solution {
public:
  bool isPowerOfThree(int n) {
    // 1162261467 is the max power of 3 in signed 32 bit integer (3^19)
    // if n is power 3, it must devide (3^19) exactly
    return n > 0 && 1162261467 % n == 0;
  }
};
