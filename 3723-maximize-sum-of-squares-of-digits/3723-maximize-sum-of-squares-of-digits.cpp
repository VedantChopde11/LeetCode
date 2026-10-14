class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;

        while(num > 0){
            if(sum < 9){
                ans += char('0' + sum);
                sum = 0;
                num--;
            }
            else if(sum >= 9){
                ans += '9';
                sum -= 9;
                num--;
            }
        }
        if(sum > 0){
            ans = "";
        }

        return ans;
    }
};