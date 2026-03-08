/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string findDifferentBinaryString(vector<string> &nums) {
    const int N = nums.size();
    unordered_set<int> numsInt;
    numsInt.reserve(N);

    for (int i = 0; i < N; ++i)
      numsInt.insert(stoi(nums[i], 0, 2));

    const auto toStr = [&N](int num) -> string {
      string s = "";

      for (int i = N - 1; i >= 0; --i)
        s += ((num >> i) & 1) ? '1' : '0';

      return s;
    };

    for (int i = 0; i <= N; ++i)
      if (!numsInt.count(i))
        return toStr(i);

    return "";
  }
};
