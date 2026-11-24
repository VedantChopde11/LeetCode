class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long long p = 1;
            long long g = 0;
            long long l = 1;
            for (int j = i; j < n; ++j) {
                if (p > 1e18 / nums[j]) break;
                p *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (p == g * l) {
                    ans = max(ans, j - i + 1);
                } else if (p > g * l) {
                    break;
                }
            }
        }
        return ans;
    }
};