#include <string>
#include <vector>

class Solution {
public:
  char findTheDifference(std::string s, std::string t) {
    int sz = s.size();
    std::vector<int> freq(26, 0);

    for (int i = 0; i < sz; ++i) {
      ++freq[t[i] - 'a'];
      --freq[s[i] - 'a'];
    }
    ++freq[t[sz] - 'a'];

    for (int i = 0; i < 25; ++i) {
      if (freq[i] == 1)
        return i + 'a';
    }

    return 'z';
  }
};
