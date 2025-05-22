#include <algorithm>
#include <iterator>
#include <string>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    std::string trimed_string = this->trim(s);
    size_t last_space_index = trimed_string.find_last_of(' ');

    if (last_space_index == std::string::npos) {
      return trimed_string.length();
    }

    return trimed_string.length() - last_space_index - 1;
  }

private:
  std::string trim(std::string s) {
    std::string::const_iterator start = std::find_if(
        s.begin(), s.end(), [](unsigned char c) { return !std::isspace(c); });
    std::string::const_iterator end =
        std::find_if(s.rbegin(), s.rend(), [](unsigned char c) {
          return !std::isspace(c);
        }).base();

    return (start < end) ? std::string(start, end) : "";
  }
};
