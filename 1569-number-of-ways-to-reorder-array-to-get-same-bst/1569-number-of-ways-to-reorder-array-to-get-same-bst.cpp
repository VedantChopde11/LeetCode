class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> choose;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return 1;

        vector<int>left,right;

        for(int i = 1; i < n; i++){
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long L = left.size();
        long long R = right.size();

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        long long interleavings = choose[L+R][L];

        return (((interleavings*leftWays) % MOD)*rightWays) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        choose.assign(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++){
            choose[i][0] = choose[i][i] = 1;

            for(int j = 1; j < i; j++){
                choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
            }
        }

        return (solve(nums)-1 + MOD) % MOD;
    }
};