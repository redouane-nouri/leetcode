#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return {};
    }

    std::vector<std::string> res;
    std::string curr;

    backtrack(digits, 0, curr, res, digits.size());

    return res;
  }

private:
  void backtrack(std::string &digits, std::size_t index, std::string &curr,
                 std::vector<std::string> &res, const std::size_t digitsSz) {
    static const std::unordered_map<char, std::string> digitToLetters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    if (index == digitsSz) {
      res.push_back(curr);
      return;
    }

    const std::string &letters = digitToLetters.at(digits[index]);

    for (std::size_t i = 0; i < letters.size(); ++i) {
      curr.push_back(letters[i]);
      backtrack(digits, index + 1, curr, res, digitsSz);
      curr.pop_back();
    }
  }
};
