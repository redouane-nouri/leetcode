/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> result;

    for (int l = 1; l <= 9; ++l) {
      int num = l, dig = l;

      for (int len = 1; len <= 9 - l + 1 && dig <= 9; ++len) {
        if (len >= 2 && num >= low && num <= high)
          result.push_back(num);

        ++dig;
        num = num * 10 + dig;
      }
    }

    sort(result.begin(), result.end());
    return result;
  }
};
