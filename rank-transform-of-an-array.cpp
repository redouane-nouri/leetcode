/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> sorArr = arr;
    sort(sorArr.begin(), sorArr.end());

    unordered_map<int, int> rank;
    for (const int &num : sorArr)
      if (rank.find(num) == rank.end())
        rank[num] = rank.size() + 1;

    vector<int> res;
    res.reserve(arr.size());

    for (const int &num : arr)
      res.push_back(rank[num]);

    return res;
  }
};
