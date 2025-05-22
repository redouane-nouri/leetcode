#include <vector>

class Solution {
public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> res(rowIndex + 1, 1);

    for (std::size_t i = 2; i <= rowIndex; ++i) {
      for (std::size_t j = i - 1; j > 0; --j) {
        res[j] = res[j] + res[j - 1];
      }
    }

    return res;
  }
};
