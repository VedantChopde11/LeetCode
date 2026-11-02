class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        long long cnt = 0;

        int mid = n/2;

        sort(nums.begin() , nums.end());

        for(int i = 0; i < n; i++){
            cnt += (abs(nums[i] - nums[mid]));
        }

        return (int)cnt;
    }
};