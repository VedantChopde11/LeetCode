
class Solution {
public:

    int solve(int i, int n, vector<int>& costs, vector<int>& dp) {

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for(int jump = 1; jump <= 3; jump++) {

            if(i + jump <= n) {

                int cost = costs[i + jump - 1] + jump * jump;

                ans = min(ans, cost + solve(i + jump, n, costs, dp));
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp( n+1, -1);
        return solve(0, n, costs, dp);
    }
};
