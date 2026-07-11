/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    const int N = arr.size();
    vector<int> freq(N + 1, 0);

    for (int &num : arr)
      ++freq[min(num, N)];

    int ans = 1;
    for (int i = 2; i <= N; ++i)
      ans = min(ans + freq[i], i);

    return ans;
  }
};
