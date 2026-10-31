class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

    
        vector<vector<array<int, 2>>> memo(
            m, vector<array<int, 2>>(n, {-2, -2})
        );

        function<int(int, int, int)> resolve =
            [&](int i, int j, int dir) -> int {

            int &ans = memo[i][j][dir];

            if (ans != -2)
                return ans;

            int ni = i;
            int nj = j;

            if (dir == 0) {
                ni++;  
            } else {
                nj++; 
            }

            if (ni >= m || nj >= n)
                return ans = -1;

            if (grid[ni][nj] == 0)
                return ans = ni * n + nj;

            return ans = resolve(ni, nj, 1 - dir);
        };

        vector<vector<long long>> dp(
            m, vector<long long>(n, 0)
        );

        dp[0][0] = 1;

        for (int sum = 0; sum < m + n - 1; sum++) {

            for (int i = 0; i < m; i++) {
                int j = sum - i;

                if (j < 0 || j >= n)
                    continue;

                if (dp[i][j] == 0)
                    continue;

                if (i == m - 1 && j == n - 1)
                    continue;

                long long ways = dp[i][j];

                if (j + 1 < n) {
                    int dest;

                    if (grid[i][j + 1] == 0) {
                        dest = i * n + (j + 1);
                    } else {
                        dest = resolve(i, j + 1, 0);
                    }

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;

                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }

                if (i + 1 < m) {
                    int dest;

                    if (grid[i + 1][j] == 0) {
                        dest = (i + 1) * n + j;
                    } else {
                        dest = resolve(i + 1, j, 1);
                    }

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;

                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};