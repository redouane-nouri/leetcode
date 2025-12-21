#include <string>
#include <vector>

class Solution {
public:
  int minDeletionSize(std::vector<std::string> &strs) {
    const int ROWS = strs.size(), COLUMNS = strs[0].size();
    std::vector<bool> sorted(ROWS - 1, false);
    int ans = 0, alreadySorted = 0;

    auto needsDelete = [&strs, &ROWS, &sorted](int &c) -> bool {
      for (int r = 0; r < ROWS - 1; ++r)
        if (!sorted[r] && strs[r][c] > strs[r + 1][c])
          return true;

      return false;
    };

    for (int c = 0; c < COLUMNS && alreadySorted < ROWS - 1; ++c) {
      if (needsDelete(c)) {
        ++ans;
        continue;
      }

      for (int r = 0; r < ROWS - 1; ++r) {
        if (!sorted[r] && strs[r][c] < strs[r + 1][c]) {
          sorted[r] = true;
          ++alreadySorted;
        }
      }
    }

    return ans;
  }
};
