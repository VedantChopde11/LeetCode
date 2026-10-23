class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int d = 0;

        vector<int> t = nums;

        sort(t.begin(),t.end());

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == t[i]) continue;
            else{
                cnt++;
                if(cnt == 1){
                    d = nums[i];
                }
                else{
                    d = d & nums[i];
                }
            }
        }
        return d;
    }
};