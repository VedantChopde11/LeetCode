class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int min_p = items[0][1];
        vector<int>freq(n + 1, 0);
        for(const auto& it : items){
            freq[it[0]]++;
            min_p = min(min_p, it[1]);
        }

        vector<int>mult(n + 1, 0);
        for(int f = 1; f <= n; ++f){
            if (freq[f] == 0) continue;
            int total = 0;
            for(int m = f; m <= n; m += f){
                total += freq[m];
            }
            mult[f] = total - 1;
        }

        vector<pair<int, int>> doubles;
        doubles.reserve(n);
        long long limit = 2LL * min_p;
        for(const auto& it : items){
            int cnt = mult[it[0]];
            if(cnt > 0 && it[1] <= limit){
                doubles.push_back({it[1], cnt});
            }
        }

        sort(doubles.begin(), doubles.end());

        long long rem = budget;
        long long ans = 0;
        for(const auto& [price, cnt] : doubles){
            if (rem < price) break;
            long long take = min((long long)cnt, rem / price);
            ans += take * 2;
            rem -= take * price;
        }

        ans += rem / min_p;
        return ans;
    }
};