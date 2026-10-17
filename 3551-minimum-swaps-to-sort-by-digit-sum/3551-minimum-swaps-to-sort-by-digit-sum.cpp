class Solution {
public:

    bool static cmp(pair<int,pair<long long,int>>& a, pair<int,pair<long long,int>>& b){
        if(a.second.first == b.second.first){
            return a.first < b.first;
        }
        return a.second.first < b.second.first;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,pair<long long,int>>>p;

        for(int i = 0; i < n; i++){
            long long sum = 0;
            long long t = nums[i];
            while(t){
                int d = t % 10;
                sum += d;
                t = t/10;
            }
            p.push_back({nums[i] , {sum , i}});
        }

        sort(p.begin() , p.end() , cmp);

        vector<bool>vis(n,false);
        int swap = 0;

        for(int i = 0; i < n; i++){
            if(vis[i] || p[i].second.second == i) continue;

            int j = i;
            int cycle = 0;

            while(!vis[j]){
                vis[j] = true;
                j = p[j].second.second;
                cycle++;;
            }

            if(cycle > 1) swap += cycle-1;
        }
        return swap;

    }
};