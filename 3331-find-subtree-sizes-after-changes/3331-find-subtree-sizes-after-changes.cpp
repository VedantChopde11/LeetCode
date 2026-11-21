class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), children(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> nearest(26, -1);

        function<void(int)> dfs = [&](int u){
            int c = s[u] - 'a';
            int prev = nearest[c];

            if(u != 0 && prev != -1){
                children[prev].push_back(u);
            } 
            else if(u != 0){
                children[parent[u]].push_back(u);
            }

            nearest[c] = u;

            for(int v : adj[u]){
                dfs(v);
            }
            nearest[c] = prev;
        };
        dfs(0);
        vector<int> ans(n, 1);
        function<int(int)> calc = [&](int u){
            for(int v : children[u]){
                ans[u] += calc(v);
            }
            return ans[u];
        };
        calc(0);
        return ans;
    }
};