class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        stack<int>st;

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                int j = i;
                int t = 0;
                while(j < n && t != 2 && s[j] == ')'){
                    t++;
                    j++;
                }
                i = j-1;
                if(!st.empty()){
                    if(t == 2) st.pop();
                    else{
                        ans += (2-t);
                        st.pop();
                    } 
                }
                else{
                    if(t == 2){
                        ans += 1;
                    }
                    else{
                        ans += (2-t + 1);
                    }
                }
            }
        }

        while(!st.empty()){
            ans += 2;
            st.pop();
        }

        return ans;
    }
};