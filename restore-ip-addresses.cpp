#include <string>
#include <vector>

class Solution {
  inline bool validSegment(const std::string &s, int start, int len, int n) {
    if ((len > 1 && s[start] == '0') || len > 3 || start + len > n)
      return false;

    int num = 0;
    for (int i = 0; i < len; ++i)
      num = num * 10 + (s[start + i] - '0');

    return num <= 255;
  }

  std::string createIp(const std::string &s, const std::vector<int> &dots,
                       int n) {
    std::string ip;
    ip.reserve(n + 3);

    ip.append(s, 0, dots[0]);
    ip.push_back('.');
    ip.append(s, dots[0], dots[1] - dots[0]);
    ip.push_back('.');
    ip.append(s, dots[1], dots[2] - dots[1]);
    ip.push_back('.');
    ip.append(s, dots[2], n - dots[2]);

    return ip;
  }

  void build(std::vector<std::string> &res, std::string &s, int start,
             int dotsPlaced, std::vector<int> &dots, int n) {
    if (start >= n)
      return;

    if (dotsPlaced == 3) {
      if (validSegment(s, start, n - start, n))
        res.push_back(createIp(s, dots, n));

      return;
    }

    int len = 1;

    do {
      dots[dotsPlaced] = start + len;
      build(res, s, start + len, dotsPlaced + 1, dots, n);
      ++len;
    } while (validSegment(s, start, len, n));

    dots[dotsPlaced] = 0;
  }

public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> res = {};
    std::vector<int> dots(3, 0);
    int n = s.size();

    if (n >= 4 && n <= 12) {
      build(res, s, 0, 0, dots, n);
    }

    return res;
  }
};
