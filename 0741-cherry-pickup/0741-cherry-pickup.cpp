class Solution {
public:
    int dp[50][50][50];

    int solve(int i, int j, int x, vector<vector<int>>& grid) {
        int n = grid.size();
        int y = i + j - x;

        if (i >= n || j >= n || x >= n || y >= n ||
            grid[i][j] == -1 || grid[x][y] == -1) {
            return INT_MIN / 2;
        }

        if (i == n - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j][x] != -1) {
            return dp[i][j][x];
        }

        int sum = grid[i][j];

        if (i != x || j != y) {
            sum += grid[x][y];
        }

        int a = solve(i + 1, j, x + 1, grid);
        int b = solve(i + 1, j, x, grid);
        int c = solve(i, j + 1, x + 1, grid);
        int d = solve(i, j + 1, x, grid);

        sum += max({a, b, c, d});

        return dp[i][j][x] = sum;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));

        return max(0, solve(0, 0, 0, grid));
    }
};