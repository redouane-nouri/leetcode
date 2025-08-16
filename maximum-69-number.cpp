class Solution {
public:
  int maximum69Number(int num) {
    int n = num, mx = num, pos = 1;

    while (n) {
      if (n % 10 == 6)
        mx = num + 3 * pos;

      pos *= 10;
      n /= 10;
    }

    return mx;
  }
};
