#include <string>
#include <vector>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    std::vector<int> freq(26, 0);
    int sz = s.length();

    if (s.length() != t.length())
      return false;

    for (int i = 0; i < sz; ++i) {
      freq[s[i] - 'a']++;
      freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; ++i) {
      if (freq[i] != 0)
        return false;
    }

    return true;
  }
};
