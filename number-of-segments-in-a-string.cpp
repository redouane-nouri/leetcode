#include <string>

class Solution {
public:
  int countSegments(std::string s) {
    int res = 0, sz = s.size();
    bool isInSegment = false;

    for (int i = 0; i < sz; ++i) {
      if (s[i] == ' ') {
        isInSegment = false;
      } else {
        if (!isInSegment) {
          ++res;
          isInSegment = true;
        }
      }
    }

    return res;
  }
};
