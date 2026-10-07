class Solution {
public:

    bool isValid(string s){
        int cnt = 0;

        for(auto it : s){
            if(it == '(') cnt++;
            if(it == ')') cnt--;

            if(cnt < 0) return false;
        }
        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        vector<string>ans;
        unordered_set<string>st;
        queue<string>q;

        q.push(s);
        st.insert(s);

        bool f = false;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string c = q.front();
                q.pop();

                if(isValid(c)){
                    ans.push_back(c);
                    f = true;
                }

                if(f) continue;

                for(int i = 0; i < c.size(); i++){
                    if(c[i] != '(' && c[i] != ')') continue;

                    string t = c.substr(0,i) + c.substr(i+1);

                    if(!st.count(t)){
                        st.insert(t);
                        q.push(t);
                    }
                }
            }
            if(f) break;

        }
        return ans;

    }
};