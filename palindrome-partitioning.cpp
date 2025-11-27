#include <string>
#include <vector>

class Solution {
  std::vector<std::vector<std::string>> ans;
  std::vector<std::string> curr;
  std::string *str;
  int n;

  bool isPalindrome(int start, int end) {
    while (start < end)
      if ((*str)[start++] != (*str)[end--])
        return false;

    return true;
  }

  void dfs(int start) {
    if (start >= n) {
      ans.push_back(curr);
      return;
    }

    for (int end = start; end < n; ++end) {
      if (isPalindrome(start, end)) {
        curr.push_back((*str).substr(start, end - start + 1));
        dfs(end + 1);
        curr.pop_back();
      }
    }
  }

public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    str = &s;
    n = s.size();

    dfs(0);

    return ans;
  }
};
