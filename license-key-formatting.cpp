#include <algorithm>
#include <string>

class Solution {
public:
  std::string licenseKeyFormatting(std::string s, int k) {
    std::string upperChars, ans;
    int count = 0;

    for (char &c : s)
      if (c != '-')
        upperChars += toupper(c);

    for (int i = upperChars.size() - 1; i >= 0; --i) {
      if (count == k) {
        ans += '-';
        count = 0;
      }

      ans += upperChars[i];
      ++count;
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
