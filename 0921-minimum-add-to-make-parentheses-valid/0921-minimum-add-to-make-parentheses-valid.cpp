class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        stack<int>st;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(st.empty()) cnt++;
                else st.pop();
            }
        }

        while(!st.empty()){
            cnt++;
            st.pop();
        }

        return cnt;
    }
};