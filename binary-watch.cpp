#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> readBinaryWatch(int turnedOn) {
    std::vector<std::string> res;

    for (int i = 0; i < 12; ++i) {
      for (int j = 0; j < 60; ++j) {
        if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn)
          res.push_back(std::to_string(i) + ":" + (j < 10 ? "0" : "") +
                        std::to_string(j));
      }
    }

    return res;
  }
};
