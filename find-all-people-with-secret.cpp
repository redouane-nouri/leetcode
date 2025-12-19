#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> findAllPeople(int n, std::vector<std::vector<int>> &meetings,
                                 int firstPerson) {
    std::unordered_set<int> knows;
    std::map<int, std::vector<std::pair<int, int>>> timeToMeetings;

    knows.insert({0, firstPerson});

    for (const auto &m : meetings)
      timeToMeetings[m[2]].push_back({m[0], m[1]});

    for (const auto &[_, groupedMeetings] : timeToMeetings) {
      std::unordered_map<int, std::vector<int>> graphs;

      for (const auto &meet : groupedMeetings) {
        graphs[meet.first].push_back(meet.second);
        graphs[meet.second].push_back(meet.first);
      }

      std::queue<int> q;
      std::unordered_set<int> visited;

      for (const auto &[person, _] : graphs)
        if (knows.count(person))
          q.push(person);

      while (!q.empty()) {
        int person = q.front();
        q.pop();
        visited.insert(person);

        for (const auto &meetedPerson : graphs[person]) {
          if (visited.count(meetedPerson))
            continue;

          knows.insert(meetedPerson);
          q.push(meetedPerson);
        }
      }
    }

    return {knows.begin(), knows.end()};
  }
};
