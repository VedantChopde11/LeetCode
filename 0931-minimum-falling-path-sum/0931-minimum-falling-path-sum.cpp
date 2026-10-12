class Solution {
public:

    int solve(int i , int j , int n, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(j < 0 || j >= n) return INT_MAX;

        if(i == n-1) return mat[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int l = solve(i+1,j-1,n,mat,dp);
        int m = solve(i+1,j,n,mat,dp);
        int r = solve(i+1 , j + 1 , n , mat, dp);

        return dp[i][j] = mat[i][j] + min({l,r,m});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // vector<vector<int>> dp(n,vector<int>(n,-1));

        // int mini = INT_MAX;

        // for(int j = 0; j < n; j++){
        //     mini = min(mini , solve(0,j,n,matrix, dp));
        // }

        // return mini;

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int j = 0; j < n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i = n-2 ; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int l = (j-1 >= 0) ? dp[i+1][j-1] : INT_MAX;
                int m = dp[i+1][j];
                int r = (j+1 < n) ? dp[i+1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({l,m,r});
            }

        }

        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            mini = min(mini , dp[0][i]);
        }

        return mini;


        
    }
};