/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> tree;

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(idx, val, node << 1, l, mid);
        else
            update(idx, val, node << 1 | 1, mid + 1, r);

        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

    int query(const int QL, const int QR, int node, int l, int r) {
        if (QL <= l && r <= QR)
            return tree[node];

        int mid = (l + r) >> 1, res = 0;

        if (QL <= mid)
            res = max(res, query(QL, QR, node << 1, l, mid));

        if (QR > mid)
            res = max(res, query(QL, QR, node << 1 | 1, mid + 1, r));

        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        const int N = queries.size(), MX = min(50000, 3 * N);
        set<int> st = {0, MX};

        tree.assign(1 << ((int)ceil(log2(MX)) + 1), 0);

        update(MX, MX, 1, 0, MX);
        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = st.upper_bound(x);
                int R = *it;
                int L = *prev(it);
                update(x, x - L, 1, 0, MX);
                update(R, R - x, 1, 0, MX);
                st.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                int pre = *prev(it);
                int best = query(0, pre, 1, 0, MX);
                best = max(best, x - pre);
                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};
