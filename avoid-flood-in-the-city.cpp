#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> avoidFlood(std::vector<int> &rains) {
    int n = rains.size();
    std::vector<int> res(n);
    std::unordered_map<int, int> lastDayRainedMap;
    std::set<int> dryDays;

    for (int i = 0; i < n; ++i) {
      if (rains[i] == 0) {
        dryDays.insert(i);
      } else {
        std::unordered_map<int, int>::iterator lastDayRained =
            lastDayRainedMap.find(rains[i]);
        if (lastDayRained != lastDayRainedMap.end()) {
          std::set<int>::iterator dryDay =
              dryDays.upper_bound(lastDayRained->second);
          if (dryDay == dryDays.end()) {
            return {};
          }
          res[*dryDay] = rains[i];
          dryDays.erase(dryDay);
        }

        lastDayRainedMap[rains[i]] = i;
        res[i] = -1;
      }
    }

    for (int d : dryDays) {
      res[d] = 1;
    }

    return res;
  }
};
