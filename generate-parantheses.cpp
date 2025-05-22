#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> r;
    std::string p;

    this->generate(0, 0, n, p, r);

    return r;
  }

private:
  void generate(int o, int c, int n, std::string &p,
                std::vector<std::string> &r) {
    if (o == n && o == c) {
      r.push_back(p);
      return;
    }

    if (o < n) {
      p.push_back('(');
      this->generate(o + 1, c, n, p, r);
      p.pop_back();
    }

    if (c < o) {
      p.push_back(')');
      this->generate(o, c + 1, n, p, r);
      p.pop_back();
    }
  }
};
