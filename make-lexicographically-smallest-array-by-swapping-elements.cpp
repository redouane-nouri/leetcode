/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU {
  unordered_map<int, int> parent, size;

  DSU(const vector<int> &nums) {
    for (const int &num : nums) {
      parent[num] = num;
      size[num] = 1;
    }
  }

  int find(const int u) {
    if (parent[u] == u)
      return u;

    return parent[u] = find(parent[u]);
  }

  void unite(int u, int v) {
    u = find(u), v = find(v);

    if (u != v) {
      if (size[u] < size[v])
        swap(u, v);

      parent[v] = u;
      size[u] += size[v];
    }
  }
};

class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
    const int N = nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    DSU dsu(sorted);

    for (int i = 1; i < N; ++i)
      if (sorted[i] - sorted[i - 1] <= limit)
        dsu.unite(sorted[i], sorted[i - 1]);

    unordered_map<int, queue<int>> mp;
    for (const int &num : sorted)
      mp[dsu.find(num)].push(num);

    for (int i = 0; i < N; ++i) {
      int group = dsu.find(nums[i]);
      nums[i] = mp[group].front();
      mp[group].pop();
    }

    return nums;
  }
};
