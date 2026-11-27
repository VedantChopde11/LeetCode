class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_f = 0;
        int min_price = items[0][1];
        for(const auto& it : items){
            max_f = max(max_f, it[0]);
            min_price = min(min_price, it[1]);
        }

        vector<long long> free_cnt(n, 0);
        if(max_f <= 200000){
            vector<int> freq(max_f + 1, 0);
            for (const auto& it : items) freq[it[0]]++;
            vector<int> mult(max_f + 1, 0);
            for (int f = 1; f <= max_f; ++f) {
                if (freq[f] == 0) continue;
                int total = 0;
                for (int m = f; m <= max_f; m += f) {
                    total += freq[m];
                }
                mult[f] = total - 1;
            }
            for(int i = 0; i < n; ++i){
                free_cnt[i] = mult[items[i][0]];
            }
        } else {
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(i != j && items[j][0] % items[i][0] == 0){
                        free_cnt[i]++;
                    }
                }
            }
        }

        vector<long long> dp(budget + 1, 0);
        for(int i = 0; i < n; ++i){
            int cost = items[i][1];
            long long val = 1 + free_cnt[i];
            for(int c = budget; c >= cost; --c){
                dp[c] = max(dp[c], dp[c - cost] + val);
            }
        }

        long long ans = 0;
        for(int c = 0; c <= budget; ++c){
            ans = max(ans, dp[c] + (budget - c) / min_price);
        }
        return ans;
    }
};