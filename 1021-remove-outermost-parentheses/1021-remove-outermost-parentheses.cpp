class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        int cnt = 0; 

        string ans;

        for(auto it : s){
            if(it == '('){
                cnt++;

                if(cnt > 1) {
                    ans += it;
                }
            }
            else{
                cnt--;

                if(cnt > 0){
                    ans += it;
                }
            }
        }

        return ans;

    }
};