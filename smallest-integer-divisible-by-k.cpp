#include <set>
class Solution {
public:
  int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0) {
      return -1;
    }

    int rem = 0, res = 0;
    std::set<int> seenRemainder;

    do {
      rem = ((rem << 3) + (rem << 1) + 1) % k;
      if (seenRemainder.count(rem)) {
        return -1;
      }
      ++res;
      seenRemainder.insert(rem);
    } while (rem);

    return res;
  }
};
