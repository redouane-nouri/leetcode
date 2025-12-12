#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int>
  countMentions(int numberOfUsers,
                std::vector<std::vector<std::string>> &events) {
    std::sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
      if (a[1] != b[1])
        return std::stoi(a[1]) < std::stoi(b[1]);
      else
        return a[0] == "OFFLINE";
    });
    std::vector<int> ans(numberOfUsers, 0);
    std::unordered_map<int, int> idToOfflineTime;

    auto incrIfOnline = [&idToOfflineTime, &ans](int i, int t) -> void {
      auto it = idToOfflineTime.find(i);
      if (it == idToOfflineTime.end()) {
        ++ans[i];
      } else if (t >= it->second + 60) {
        idToOfflineTime.erase(it);
        ++ans[i];
      }
    };

    for (auto &e : events) {
      if (e[0] == "OFFLINE") {
        idToOfflineTime[std::stoi(e[2])] = std::stoi(e[1]);
        continue;
      }

      if (e[2] == "ALL") {
        for (int &a : ans)
          ++a;
        continue;
      }

      int t = std::stoi(e[1]);

      if (e[2] == "HERE") {

        for (int i = 0; i < numberOfUsers; ++i)
          incrIfOnline(i, t);

        continue;
      }

      std::stringstream ss(e[2]);
      std::string strId;

      while (ss >> strId)
        ++ans[std::stoi(strId.substr(2))];
    }

    return ans;
  }
};
