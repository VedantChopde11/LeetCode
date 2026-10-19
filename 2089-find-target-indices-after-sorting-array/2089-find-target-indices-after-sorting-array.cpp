class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>arr;

        sort(nums.begin() , nums.end());

        for(int i = 0; i < n; i++){
            if(nums[i] == target) arr.push_back(i);
        }

        return arr;
    }
};