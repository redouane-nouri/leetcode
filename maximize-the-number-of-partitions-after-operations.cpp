#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>

class Solution {
  std::string s;
  int k, n;
  std::unordered_map<long long, int> memo;

  int dfs(int i, int countBitMask, int canChange) {
    if (i == n)
      return 1;

    long long key =
        ((long long)i << 32) | ((long long)countBitMask << 1) | canChange;

    std::unordered_map<long long, int>::iterator it = memo.find(key);
    if (it != memo.end()) {
      return it->second;
    }

    int charBitMask = 1 << (s[i] - 'a'),
        nextCountBitMask = countBitMask | charBitMask, res;

    if (__builtin_popcount(nextCountBitMask) > k) {
      res = 1 + dfs(i + 1, charBitMask, canChange);
    } else {
      res = dfs(i + 1, nextCountBitMask, canChange);
    }

    if (canChange) {
      for (int j = 0; j < 26; ++j) {
        int nextCountBitMaskChanged = countBitMask | (1 << j);
        if (__builtin_popcount(nextCountBitMaskChanged) > k) {
          res = std::max(res, 1 + dfs(i + 1, 1 << j, 0));
        } else {
          res = std::max(res, dfs(i + 1, nextCountBitMaskChanged, 0));
        }
      }
    }

    memo[key] = res;
    return res;
  }

public:
  int maxPartitionsAfterOperations(std::string s, int k) {
    n = s.size();
    this->s = std::move(s);
    this->k = k;
    memo.reserve(n << 5);
    return dfs(0, 0, 1);
  }
};
