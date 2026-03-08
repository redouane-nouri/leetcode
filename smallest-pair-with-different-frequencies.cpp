#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> minDistinctFreqPair(vector<int> &nums) {
    unordered_map<int, int> freq;
    set<int> unique(nums.begin(), nums.end());

    for (const int &num : nums)
      freq[num]++;

    for (auto it = unique.begin(); it != unique.end(); ++it) {
      for (auto it2 = next(it); it2 != unique.end(); ++it2) {
        if (freq[*it] != freq[*it2])
          return {*it, *it2};
      }
    }

    return {-1, -1};
  }
};
