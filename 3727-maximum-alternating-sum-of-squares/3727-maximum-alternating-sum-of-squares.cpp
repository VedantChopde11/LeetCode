class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n; i++){
            if(nums[i] < 0) nums[i] = abs(nums[i]);
        }

        sort(nums.begin() , nums.end());

        long long sum = 0;

        int l = 0 , r = n-1;

        int cnt = 0;

        while(l <= r){
            if(cnt % 2 == 0){
                sum += (nums[r] * nums[r]);
                r--;
            }
            else{
                sum -= (nums[l] * nums[l]);
                l++;
            }
            cnt++;
        }
        return sum;
    }
};