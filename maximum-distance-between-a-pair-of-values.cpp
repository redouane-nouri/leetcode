/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    const int N = nums1.size(), M = nums2.size();
    int i = 0, j = 0, ans = 0;

    while (i < N && j < M)
      nums1[i] <= nums2[j] ? (++j)
                           : (ans = max(ans, j - i - 1), ++i, j = max(j, i));

    ans = max(ans, j - i - 1);

    return ans;
  }
};
