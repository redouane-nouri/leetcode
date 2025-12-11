#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int countCoveredBuildings(int n, std::vector<std::vector<int>> &buildings) {
    std::unordered_map<int, std::vector<int>> xToYs, yToXs;

    for (auto &b : buildings) {
      xToYs[b[0]].push_back(b[1]);
      yToXs[b[1]].push_back(b[0]);
    }

    for (auto it = xToYs.begin(); it != xToYs.end(); ++it)
      std::sort(it->second.begin(), it->second.end());

    for (auto it = yToXs.begin(); it != yToXs.end(); ++it)
      std::sort(it->second.begin(), it->second.end());

    auto inMiddle = [](auto &m, int &key, int &value) -> bool {
      if (m[key].size() < 3)
        return false;

      auto first = m[key].front(), last = m[key].back();

      return ((first != value) && (last != value));
    };

    int ans = 0;
    for (auto &b : buildings)
      if (inMiddle(xToYs, b[0], b[1]) && inMiddle(yToXs, b[1], b[0]))
        ++ans;

    return ans;
  }
};
