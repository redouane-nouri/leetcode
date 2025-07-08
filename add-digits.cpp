class Solution {
public:
  int addDigits(int num) {
    if (num == 0)
      return 0;

    // The sum of a number’s digits is the same as num % 9.
    // If num is a multiple of 9, the result should be 9 (not 0).
    // Digital root formula handles all cases including multiples of 9.
    return 1 + (num - 1) % 9;
  }
};
