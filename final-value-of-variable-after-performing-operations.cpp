#include <string>
#include <vector>

class Solution {
public:
  int finalValueAfterOperations(std::vector<std::string> &operations) {
    int x = 0;

    for (std::string &o : operations) {
      if (o[1] == '+') {
        ++x;
      } else {
        --x;
      }
    }

    return x;
  }
};
