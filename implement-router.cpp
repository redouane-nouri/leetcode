#include <algorithm>
#include <array>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

class Router {
  int memoryLimit;
  std::queue<std::array<int, 3>> q;
  std::set<std::array<int, 3>> s;
  std::unordered_map<int, std::vector<int>> destTimestamps;
  std::unordered_map<int, int> idx;

public:
  Router(int memoryLimit) { this->memoryLimit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    if (s.count({source, destination, timestamp}))
      return false;

    if (q.size() == memoryLimit) {
      std::array<int, 3> f = q.front();
      q.pop();
      s.erase(f);
      ++idx[f[1]];
      if (idx[f[1]] == destTimestamps[f[1]].size()) {
        destTimestamps.erase(f[1]);
        idx.erase(f[1]);
      }
    }

    q.push({source, destination, timestamp});
    s.insert({source, destination, timestamp});

    destTimestamps[destination].push_back(timestamp);
    return true;
  }

  std::vector<int> forwardPacket() {
    if (q.empty())
      return {};

    std::array<int, 3> f = q.front();
    q.pop();
    s.erase(f);

    ++idx[f[1]];
    if (idx[f[1]] == destTimestamps[f[1]].size()) {
      destTimestamps.erase(f[1]);
      idx.erase(f[1]);
    }

    return {f[0], f[1], f[2]};
  }

  int getCount(int destination, int startTime, int endTime) {
    if (!destTimestamps.count(destination))
      return 0;

    std::vector<int> &v = destTimestamps[destination];

    int start = std::lower_bound(v.begin(), v.end(), startTime) - v.begin();
    int end = std::upper_bound(v.begin(), v.end(), endTime) - v.begin();

    return std::max(end, idx[destination]) - std::max(start, idx[destination]);
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
