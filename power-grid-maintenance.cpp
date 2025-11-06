#include <queue>
#include <set>
#include <vector>

class Solution {
  void bfs(const int i, std::vector<int> &componentOf,
           const std::vector<std::vector<int>> &connectedWith,
           const int componentId) {
    componentOf[i] = componentId;
    std::queue<int> q;
    q.push(i);

    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (int id : connectedWith[f]) {
        if (componentOf[id] == -1) {
          componentOf[id] = componentId;
          q.push(id);
        }
      }
    }
  }

public:
  std::vector<int> processQueries(int c,
                                  std::vector<std::vector<int>> &connections,
                                  std::vector<std::vector<int>> &queries) {
    std::vector<std::vector<int>> connectedWith(c + 1);

    for (auto &con : connections) {
      connectedWith[con[0]].push_back(con[1]);
      connectedWith[con[1]].push_back(con[0]);
    }

    std::vector<int> componentOf(c + 1, -1);
    int componentId = 0;
    for (int i = 1; i <= c; ++i) {
      if (componentOf[i] == -1) {
        bfs(i, componentOf, connectedWith, componentId++);
      }
    }

    std::vector<std::set<int>> componentsNodes(componentId);
    for (int i = 1; i <= c; ++i) {
      componentsNodes[componentOf[i]].insert(i);
    }

    std::vector<int> res;
    res.reserve(queries.size());

    for (auto &q : queries) {
      auto &componentNodes = componentsNodes[componentOf[q[1]]];

      if (q[0] == 2) {
        componentNodes.erase(q[1]);
      } else {
        if (componentNodes.count(q[1])) {
          res.push_back(q[1]);
        } else {
          res.push_back(componentNodes.empty() ? -1 : *componentNodes.begin());
        }
      }
    }

    return res;
  }
};
