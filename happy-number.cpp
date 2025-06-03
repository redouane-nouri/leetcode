class Solution {
public:
  bool isHappy(int n) {
    // floyd's cycle detection
    int slow = n, fast = n;

    do {
      slow = squareSum(slow);
      fast = squareSum(squareSum(fast));

      if (fast == 1) {
        return true;
      }
    } while (slow != fast);

    return false;
  }

private:
  int squareSum(int num) {
    int sum = 0, digit;

    while (num) {
      digit = num % 10;
      sum += digit * digit;
      num /= 10;
    }

    return sum;
  }
};
