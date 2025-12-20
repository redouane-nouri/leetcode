#include <string>
#include <vector>

class Solution {
public:
  int minDeletionSize(std::vector<std::string> &strs) {
    const int RN = strs.size(), CN = strs[0].size();

    const auto toDelete = [&strs, &RN](const int &c) -> bool {
      for (int r = 1; r < RN; ++r)
        if (strs[r][c] < strs[r - 1][c])
          return true;

      return false;
    };

    int ans = 0;
    for (int c = 0; c < CN; ++c)
      if (toDelete(c))
        ++ans;

    return ans;
  }
};
