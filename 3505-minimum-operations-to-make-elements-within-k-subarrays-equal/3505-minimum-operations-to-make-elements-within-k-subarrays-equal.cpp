
class Solution {
public:
    vector<vector<long long>> dp;
    vector<long long> cost;
    int n, x;

    long long solve(int i, int j) {

        if (j == 0) return 0;

        if (i < j * x) return LLONG_MAX / 4;

        if (dp[i][j] != -1)
            return dp[i][j];

     
        long long notTake = solve(i - 1, j);

        long long take = solve(i - x, j - 1) + cost[i - x];

        return dp[i][j] = min(take, notTake);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        n = nums.size();
        this->x = x;

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;

                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;

                low.insert(v);
                sumLow += v;
            }
        };

        auto add = [&](int v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = low.find(v);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= v;
            } else {
                it = high.find(v);
                high.erase(it);
                sumHigh -= v;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long med = *low.rbegin();

            return med * low.size() - sumLow
                 + sumHigh - med * high.size();
        };

        cost.resize(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x)
                remove(nums[i - x]);

            if (i >= x - 1)
                cost[i - x + 1] = getCost();
        }

        dp.assign(n + 1, vector<long long>(k + 1, -1));

        return solve(n, k);
    }
};
