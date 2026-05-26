/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> jumps;
    int N, D;

public:
    void dfs(vector<int>& arr, int id) {
        if (jumps[id] != -1)
            return;

        jumps[id] = 1;

        for (int i = id - 1; i >= 0 && id - i <= D && arr[id] > arr[i]; --i) {
            dfs(arr, i);
            jumps[id] = max(jumps[id], jumps[i] + 1);
        }

        for (int i = id + 1; i < N && i - id <= D && arr[id] > arr[i]; ++i) {
            dfs(arr, i);
            jumps[id] = max(jumps[id], jumps[i] + 1);
        }
    }

    int maxJumps(vector<int>& arr, int d) {
        N = arr.size();
        D = d;

        jumps.resize(N, -1);

        for (int i = 0; i < N; ++i)
            dfs(arr, i);

        return *max_element(jumps.begin(), jumps.end());
    }
};
