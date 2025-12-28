#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int mostBooked(int n, std::vector<std::vector<int>> &meetings) {
    std::priority_queue<std::pair<long long, int>,
                        std::vector<std::pair<long long, int>>,
                        std::greater<std::pair<long long, int>>>
        busyPQ;
    std::priority_queue<int, std::vector<int>, std::greater<int>> freePQ;
    std::vector<int> freq(n, 0);
    const int MN = meetings.size();

    std::sort(meetings.begin(), meetings.end());

    for (int i = 0; i < n && i < MN; ++i)
      freePQ.push(i);

    for (int i = 0; i < MN; ++i) {
      const int &start = meetings[i][0], &end = meetings[i][1];

      while (!busyPQ.empty() && busyPQ.top().first <= start) {
        freePQ.push(busyPQ.top().second);
        busyPQ.pop();
      }

      if (!freePQ.empty()) {
        const int roomId = freePQ.top();
        freePQ.pop();
        busyPQ.push({end, roomId});
        ++freq[roomId];
        continue;
      }

      const auto t = busyPQ.top();
      busyPQ.pop();

      ++freq[t.second];
      busyPQ.push({t.first + (end - start), t.second});
    }

    int ans = 0;
    for (int i = 1; i < n; ++i)
      if (freq[i] > freq[ans])
        ans = i;

    return ans;
  }
};
