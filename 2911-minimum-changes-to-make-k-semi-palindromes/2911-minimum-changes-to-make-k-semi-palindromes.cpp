class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> divs(n + 1);
        for(int i = 1; i <= n; ++i){
            for(int j = i * 2; j <= n; j += i){
                divs[j].push_back(i);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int len = j - i + 1;
                int min_c = 1e9;
                for(int d : divs[len]){
                    int c = 0;
                    for(int offset = 0; offset < d; ++offset){
                        int left = i + offset;
                        int right = i + offset + (len / d - 1) * d;
                        while(left < right){
                            if(s[left] != s[right]){
                                c++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    min_c = min(min_c, c);
                }
                cost[i][j] = min_c;
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;
        for(int p = 1; p <= k; ++p){
            for(int i = p * 2; i <= n; ++i){
                for(int j = (p - 1) * 2; j <= i - 2; ++j){
                    if (dp[p - 1][j] != 1e9) {
                        dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                    }
                }
            }
        }
        return dp[k][n];
    }
};