class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        int sum = n;

        for(int k = 2; k <= n; k++){
            int l = 0 , r = n-1;
            vector<int>vis(101,0);
         

            for(int r = 0; r < n; r++){
                vis[nums[r]]++;

                while(r-l+1 > k){
                    vis[nums[l]]--;
                    l++;
                }

                if(r-l+1 == k){
                    int cnt = 0;
                    for(auto it : vis){
                        if(it > 0) cnt++;
                    }
                    sum += cnt*cnt;

                }

            }
         
        }
        return sum;
    }
};