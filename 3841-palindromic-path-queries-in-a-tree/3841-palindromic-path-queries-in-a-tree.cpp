#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtree;
    vector<int> seg;

    int dfs(int u, int p) {
        parent[u] = p;
        subtree[u] = 1;
        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int size = dfs(v, u);
            subtree[u] += size;

            if (size > maxSize) {
                maxSize = size;
                heavy[u] = v;
            }
        }

        return subtree[u];
    }

    void decompose(int u, int h, int &timer) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h, timer);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v, timer);
        }
    }

    void build(vector<int>& base, int node, int l, int r) {
        if (l == r) {
            seg[node] = base[l];
            return;
        }

        int mid = (l + r) / 2;
        build(base, node * 2, l, mid);
        build(base, node * 2 + 1, mid + 1, r);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathQuery(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }

public:
    vector<bool> palindromePath(int n,vector<vector<int>>& edges,string s,vector<string>& queries) {
        this->n = n;
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtree.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);

        int timer = 0;
        decompose(0, 0, timer);

        vector<int> base(n);

        for (int i = 0; i < n; i++)
            base[pos[i]] = 1 << (s[i] - 'a');

        seg.assign(4 * n, 0);
        build(base, 1, 0, n - 1);

        vector<bool> answer;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v);

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};