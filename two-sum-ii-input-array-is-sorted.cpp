/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1;

    while (l < r) {
      int s = numbers[l] + numbers[r];

      if (s == target)
        return {l + 1, r + 1};
      else if (s < target)
        ++l;
      else
        --r;
    }

    return {-1, -1};
  }
};
