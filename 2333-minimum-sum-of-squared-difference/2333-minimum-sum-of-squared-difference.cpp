class Solution {
public:

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<long long> freq(100001, 0);
        long long total = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
            maxi = max(maxi, d);
        }

        if (k >= total) return 0;

        for (int d = maxi; d > 0 && k > 0; d--) {
            long long count = freq[d];
            if (count == 0) continue;

            long long operations = min(k, count);
            freq[d] -= operations;
            freq[d - 1] += operations;
            k -= operations;
        }

        long long sum = 0;

        for (int d = 1; d < (int)freq.size(); d++) {
            sum += freq[d] * d * d;
        }


        return sum;
    }
};