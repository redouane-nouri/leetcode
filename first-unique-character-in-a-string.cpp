#include <string>
#include <vector>

class Solution {
public:
  int firstUniqChar(std::string s) {
    std::vector<int> unique(26, 0);
    int sz = s.size();

    for (int i = 0; i < sz; ++i) {
      if (unique[s[i] - 'a'] == -1)
        continue;

      if (unique[s[i] - 'a'] == 0)
        unique[s[i] - 'a'] = i + 1;
      else
        unique[s[i] - 'a'] = -1;
    }

    int res = 0;
    for (int i = 0; i < 26; ++i) {
      if (unique[i] > 0 && (res == 0 || res > unique[i]))
        res = unique[i];
    }

    return --res;
  }
};
