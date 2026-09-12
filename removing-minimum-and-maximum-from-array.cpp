/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  int minimumDeletions(vector<int> &nums) {
    const int N = nums.size();
    int mni = 0, mxi = 0;

    for (int i = 1; i < N; ++i) {
      if (nums[i] < nums[mni])
        mni = i;

      if (nums[i] > nums[mxi])
        mxi = i;
    }

    if (mni > mxi)
      swap(mni, mxi);

    return min({mxi + 1, N - mni, mni + 1 + N - mxi});
  }
};
