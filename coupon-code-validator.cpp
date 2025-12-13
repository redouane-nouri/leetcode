#include <algorithm>
#include <regex>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string>
  validateCoupons(std::vector<std::string> &code,
                  std::vector<std::string> &businessLine,
                  std::vector<bool> &isActive) {
    const std::regex REG("^[A-Za-z0-9_]+$");
    const auto isValidCategory = [](const std::string &s) -> bool {
      return s == "electronics" || s == "grocery" || s == "pharmacy" ||
             s == "restaurant";
    };
    const int N = code.size();

    std::vector<int> validItems;

    for (int i = 0; i < N; ++i)
      if (isActive[i] && std::regex_match(code[i], REG) &&
          isValidCategory(businessLine[i]))
        validItems.push_back(i);

    std::sort(validItems.begin(), validItems.end(),
              [&businessLine, &code](const int &a, const int &b) {
                char ca = businessLine[a][0], cb = businessLine[b][0];
                if (ca != cb)
                  return ca < cb;

                return code[a] < code[b];
              });

    std::vector<std::string> ans;
    ans.reserve(validItems.size());

    for (const int &i : validItems)
      ans.push_back(code[i]);

    return ans;
  }
};
