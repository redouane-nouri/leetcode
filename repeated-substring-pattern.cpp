#include <string>

class Solution {
public:
  bool repeatedSubstringPattern(std::string s) {
    return (s + s).substr(1, s.size() * 2 - 2).find(s) != std::string::npos;
  }
};
