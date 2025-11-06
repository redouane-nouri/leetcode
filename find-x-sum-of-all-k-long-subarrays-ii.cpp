#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

struct Cmp {
  bool operator()(const std::array<int, 2> &a,
                  const std::array<int, 2> &b) const {
    if (a[1] == b[1]) {
      return a[0] > b[0];
    }

    return a[1] > b[1];
  }
};
class Solution {
public:
  std::vector<long long> findXSum(std::vector<int> &nums, int k, int x) {
    int n = nums.size();
    std::unordered_map<int, int> countMap;
    std::set<std::array<int, 2>, Cmp> topSet, otherSet;
    long long sum = 0;
    std::vector<long long> res;

    countMap.reserve(k * 2);
    res.reserve(n - k + 1);

    auto moveFirstOtherToTop = [&topSet, &otherSet, &sum]() -> void {
      if (!otherSet.empty()) {
        auto it = otherSet.begin();
        topSet.insert(*it);
        sum += 1LL * (*it)[0] * (*it)[1];
        otherSet.erase(it);
      }
    };

    auto moveLastTopToRes = [&topSet, &otherSet, &sum]() -> void {
      auto it = std::prev(topSet.end());
      otherSet.insert(*it);
      sum -= 1LL * (*it)[0] * (*it)[1];
      topSet.erase(it);
    };

    auto needSwap = [&topSet, &otherSet]() -> bool {
      if (!otherSet.empty()) {
        auto lastTopSet = *std::prev(topSet.end()),
             firstOtherSet = *otherSet.begin();

        if (lastTopSet[1] < firstOtherSet[1]) {
          return true;
        }

        if (lastTopSet[1] == firstOtherSet[1] &&
            lastTopSet[0] < firstOtherSet[0]) {
          return true;
        }
      }

      return false;
    };

    auto balance = [&topSet, &otherSet, &sum, &x, &countMap, &moveLastTopToRes,
                    &moveFirstOtherToTop, &needSwap]() -> void {
      int xElemMax = std::min(x, static_cast<int>(countMap.size()));

      while (static_cast<int>(topSet.size()) > xElemMax) {
        moveLastTopToRes();
      }

      while (!otherSet.empty() && static_cast<int>(topSet.size()) < xElemMax) {
        moveFirstOtherToTop();
      }

      while (needSwap()) {
        std::array<int, 2> top = *std::prev(topSet.end());
        std::array<int, 2> other = *otherSet.begin();

        topSet.erase(std::prev(topSet.end()));
        otherSet.erase(otherSet.begin());

        sum -= 1LL * top[0] * top[1];
        sum += 1LL * other[0] * other[1];

        topSet.insert(other);
        otherSet.insert(top);
      }
    };

    auto update = [&topSet, &otherSet, &countMap, &sum,
                   &balance](int v, int delta) -> void {
      int c = 0;
      auto it = countMap.find(v);
      if (it != countMap.end()) {
        c = it->second;
      }

      if (c > 0) {
        std::array<int, 2> vc = {v, c};
        if (topSet.count(vc)) {
          topSet.erase(topSet.find(vc));
          sum -= 1LL * v * c;
        } else {
          if (otherSet.count(vc)) {
            otherSet.erase(otherSet.find(vc));
          }
        }
      }

      int nc = c + delta;

      if (nc <= 0) {
        if (it != countMap.end()) {
          countMap.erase(it);
        }
      } else {
        countMap[v] = nc;
        otherSet.insert({v, nc});
      }
      balance();
    };

    for (int i = 0; i < k; ++i) {
      ++countMap[nums[i]];
    }

    for (auto &count : countMap) {
      otherSet.insert({count.first, count.second});
    }

    int xElemMax = std::min(x, static_cast<int>(countMap.size()));
    for (int i = 0; i < xElemMax; ++i) {
      moveFirstOtherToTop();
    }
    res.push_back(sum);

    for (int i = k; i < n; ++i) {
      update(nums[i - k], -1);
      update(nums[i], 1);
      res.push_back(sum);
    }

    return res;
  }
};
