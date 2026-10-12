class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>cnt(31,0);
        const int MOD = 1e9+7;

        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < 31; j++){
                if(nums[i] & (1 << j)){
                    cnt[j]++;
                }
            }
        }

        long long ans = 0;

        for(int i = 0; i < k; i++){
            long long x = 0;
            for(int j = 0; j < 31; j++){
                if(cnt[j] > 0){
                    x |= (1LL << j);
                    cnt[j]--;
                }
            }

            ans = (ans + x*x) % MOD;
        }
        return ans;
    }
};