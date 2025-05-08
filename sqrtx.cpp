class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }

    unsigned int low = 1, high = x, result = 0;
    unsigned long long mid_square, mid;

    while (low <= high) {
      mid = low + (high - low) / 2;
      mid_square = mid * mid;

      if (mid_square == x) {
        return mid;
      } else if (mid_square < x) {
        result = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return result;
  }
};
