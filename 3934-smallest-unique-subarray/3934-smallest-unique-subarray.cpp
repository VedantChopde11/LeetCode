class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;
        }

        const long long m1 = 1000000007, m2 = 1000000009;
        const long long b1 = 1000003, b2 = 1000033;

        auto modPow = [](long long base, int exp, long long mod) {
            long long res = 1;
            while (exp > 0) {
                if (exp & 1) res = (res * base) % mod;
                base = (base * base) % mod;
                exp >>= 1;
            }
            return res;
        };

        auto hasUnique = [&](int L) {
            long long h1 = 0, h2 = 0;
            long long p1 = modPow(b1, L - 1, m1);
            long long p2 = modPow(b2, L - 1, m2);

            for (int i = 0; i < L; ++i) {
                h1 = (h1 * b1 + arr[i]) % m1;
                h2 = (h2 * b2 + arr[i]) % m2;
            }

            unordered_map<uint64_t, int> counts;
            counts.reserve(n - L + 1);
            counts[(uint64_t(h1) << 32) | uint64_t(h2)]++;

            for (int i = L; i < n; ++i) {
                h1 = (h1 - arr[i - L] * p1 % m1 + m1) % m1;
                h1 = (h1 * b1 + arr[i]) % m1;
                h2 = (h2 - arr[i - L] * p2 % m2 + m2) % m2;
                h2 = (h2 * b2 + arr[i]) % m2;
                counts[(uint64_t(h1) << 32) | uint64_t(h2)]++;
            }

            for (const auto& [k, c] : counts) {
                if (c == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};