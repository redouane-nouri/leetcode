#include <string>
#include <vector>

class Solution {
public:
  std::string getPermutation(int n, int k) {
    int fac = 1;
    std::vector<int> numbers;

    numbers.reserve(n);

    for (int i = 1; i < n; i++) {
      numbers.push_back(i);
      fac *= i;
    }
    numbers.push_back(n);

    k--;
    std::string res;
    res.reserve(n);

    while (true) {
      int i = k / fac;

      res.push_back(numbers[i] + '0');
      numbers.erase(numbers.begin() + i);

      if (numbers.empty())
        break;

      k = k % fac;
      fac /= numbers.size();
    }

    return res;
  }
};
