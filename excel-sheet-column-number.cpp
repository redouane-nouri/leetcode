#include <string>

class Solution {
public:
  int titleToNumber(std::string columnTitle) {
    const std::size_t size = columnTitle.size();
    int res = 0;
    for (std::size_t i = 0; i < size; ++i) {
      res = (res * 26) + (columnTitle[i] - 'A') + 1;
    }

    return res;
  }
};
