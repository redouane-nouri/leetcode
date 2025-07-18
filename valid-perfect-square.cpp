class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 1)
      return 1;

    int l = 0, r = num / 2;

    while (l <= r) {
      int m = l + (r - l) / 2;
      long mxm = 1LL * m * m;

      if (mxm == num)
        return true;
      else if (mxm < num)
        l = m + 1;
      else
        r = m - 1;
    }

    return false;
  }
};
