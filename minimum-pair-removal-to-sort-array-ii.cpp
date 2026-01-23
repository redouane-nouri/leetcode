#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    const int N = nums.size();
    vector<long long> s(nums.begin(), nums.end());
    set<pair<long long, int>> minHeap;
    vector<int> next(N);
    vector<int> prev(N);
    for (int i = 0; i < N; ++i) {
      prev[i] = i - 1;
      next[i] = i + 1;
    }
    int ans = 0;
    int decreasing = 0;
    for (int i = 0; i < N - 1; ++i) {
      if (s[i] > s[i + 1])
        ++decreasing;
      minHeap.insert({s[i] + s[i + 1], i});
    }
    while (decreasing) {
      int currIdx = minHeap.begin()->second;
      int nextIdx = next[currIdx];
      int prevIdx = prev[currIdx];
      int nextNextIdx = next[nextIdx];
      if (s[currIdx] > s[nextIdx])
        decreasing--;
      if (prevIdx >= 0) {
        if (s[prevIdx] > s[currIdx] && s[prevIdx] <= s[currIdx] + s[nextIdx]) {
          --decreasing;
        } else if (s[prevIdx] <= s[currIdx] &&
                   s[prevIdx] > s[currIdx] + s[nextIdx]) {
          ++decreasing;
        }
      }
      if (nextNextIdx < N) {
        if (s[nextNextIdx] >= s[nextIdx] &&
            s[nextNextIdx] < s[currIdx] + s[nextIdx]) {
          ++decreasing;
        } else if (s[nextNextIdx] < s[nextIdx] &&
                   s[nextNextIdx] >= s[currIdx] + s[nextIdx]) {
          --decreasing;
        }
      }
      minHeap.erase(minHeap.begin());
      if (prevIdx >= 0) {
        minHeap.erase({s[prevIdx] + s[currIdx], prevIdx});
        minHeap.insert({s[prevIdx] + s[currIdx] + s[nextIdx], prevIdx});
      }
      if (nextNextIdx < N) {
        minHeap.erase({s[nextIdx] + s[nextNextIdx], nextIdx});
        minHeap.insert({s[nextNextIdx] + s[nextIdx] + s[currIdx], currIdx});
        prev[nextNextIdx] = currIdx;
      }
      next[currIdx] = nextNextIdx;
      s[currIdx] = s[currIdx] + s[nextIdx];
      ans++;
    }
    return ans;
  }
};
