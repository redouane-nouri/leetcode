#include <string>

class Solution {
public:
  int countCollisions(std::string directions) {
    int ans = 0, rc = 0;
    char last = directions[0];

    for (char &c : directions) {
      switch (c) {
      case 'R':
        last = 'R';
        ++rc;
        break;

      case 'S':
        ans += rc;
        rc = 0;
        last = 'S';
        break;

      case 'L':
        ans += last == 'L' ? 0 : rc + 1;
        rc = 0;
        last = last != 'L' ? 'S' : 'L';
        break;
      }
    }

    return ans;
  }
};
