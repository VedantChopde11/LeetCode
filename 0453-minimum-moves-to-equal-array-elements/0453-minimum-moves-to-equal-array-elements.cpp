class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        long long ans = 0;
        for(int i = n-1; i >= 1; i--){
            ans += (nums[i] - nums[0]);
        }

        return (int)ans;
    }
};