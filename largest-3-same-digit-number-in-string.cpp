#include <string>

class Solution {
public:
  std::string largestGoodInteger(std::string num) {
    char c = '\0';
    int n = num.size();

    for (int i = 0; i + 2 < n; ++i) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        c = num[i] > c ? num[i] : c;
        i += 2;
      }
    }

    return c ? std::string(3, c) : "";
  }
};
