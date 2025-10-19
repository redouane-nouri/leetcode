#include <queue>
#include <string>
#include <unordered_set>

class Solution {
public:
  std::string findLexSmallestString(std::string s, int a, int b) {
    std::unordered_set<std::string> seen;
    std::queue<std::string> q;
    int n = s.size();
    seen.insert(s);
    q.push(s);

    std::string res = s;
    while (!q.empty()) {
      std::string f = q.front();
      q.pop();

      if (f < res) {
        res = f;
      }

      std::string added = f;
      for (int i = 1; i < n; i += 2) {
        int d = added[i] - '0' + a;
        if (d >= 10) {
          d -= 10;
        }
        added[i] = d + '0';
      }

      if (!seen.count(added)) {
        seen.insert(added);
        q.push(added);
      }

      std::string rotated = f.substr(n - b) + f.substr(0, n - b);
      if (!seen.count(rotated)) {
        seen.insert(rotated);
        q.push(rotated);
      }
    }

    return res;
  }
};
