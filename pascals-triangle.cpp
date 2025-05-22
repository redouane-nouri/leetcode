#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result = {{1}};

    for (std::size_t i = 1; i < numRows; ++i) {
      std::vector<int> current_line(i + 1);
      current_line[0] = current_line[i] = 1;

      for (std::size_t j = 1; j < i; ++j) {
        current_line[j] = result[i - 1][j - 1] + result[i - 1][j];
      }

      result.push_back(current_line);
    }

    return result;
  }
};
