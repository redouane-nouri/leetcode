#include <string>
#include <vector>

class Solution {
public:
  std::string simplifyPath(std::string path) {
    std::vector<std::string> tokens;
    int sz = path.size(), i = 1;

    std::string token;

    while (i < sz) {
      while (i < sz && path[i] == '/')
        ++i;

      token.clear();

      while (i < sz && path[i] != '/')
        token += path[i++];

      if (!token.empty()) {
        if (token == ".")
          continue;

        if (token == "..") {
          if (!tokens.empty())
            tokens.pop_back();

          continue;
        }

        tokens.push_back(token);
      }
    }

    path.clear();

    for (std::string &token : tokens)
      path += ("/" + token);

    return path.empty() ? "/" : path;
  }
};
