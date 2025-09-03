#include <string>
#include <vector>

class Solution {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int n = s1.size(), m = s2.size();

    if (n + m != s3.size())
      return false;

    std::vector<bool> d(m + 1);
    d[0] = true;

    for (int j = 1; j <= m; ++j)
      d[j] = d[j - 1] && (s3[j - 1] == s2[j - 1]);

    for (int i = 1; i <= n; ++i) {
      d[0] = d[0] && (s1[i - 1] == s3[i - 1]);
      for (int j = 1; j <= m; ++j)
        d[j] = (d[j] && s1[i - 1] == s3[i + j - 1]) ||
               (d[j - 1] && s2[j - 1] == s3[i + j - 1]);
    }

    return d[m];
  }
};
