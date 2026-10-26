class Solution {
public:
    long long dfs(vector<vector<int>>& grid , int i , int j , int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return 0;
        }

        long long sum = 0;
        if(grid[i][j] > 0) sum += grid[i][j];

        grid[i][j] = 0;

        sum += dfs(grid,i+1,j,m,n);
        sum += dfs(grid,i-1,j,m,n);
        sum += dfs(grid,i,j+1,m,n);
        sum += dfs(grid,i,j-1,m,n);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    long long sum =  dfs(grid,i,j,m,n);
                    if(sum % k == 0){
                        cnt++;
                    } 
                }
            }
        }

        return cnt;
    }
};