#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int numberOfSubstrings(std::string s) {
    const int n = s.size();
    std::vector<int> zeroes(n + 1);

    zeroes[0] = -1;
    for (int i = 1; i <= n; ++i) {
      if (i == 1 || s[i - 2] == '0') {
        zeroes[i] = i - 1;
      } else {
        zeroes[i] = zeroes[i - 1];
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      int cz = s[i] == '0';
      int zi = i + 1;

      while (zi > 0 && cz * cz <= n) {
        int co = (i - zeroes[zi] + 1) - cz;

        if (co >= cz * cz) {
          res += std::min(zi - zeroes[zi], co - cz * cz + 1);
        }

        zi = zeroes[zi];
        ++cz;
      }
    }

    return res;
  }
};
