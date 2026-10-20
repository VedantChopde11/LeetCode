
class Solution {
public:
    bool isRotation(const vector<int>& a, const vector<int>& b) {
        int m = a.size();
        vector<int> lps(m, 0);

        for (int i = 1, len = 0; i < m; ) {
            if (b[i] == b[len]) {
                lps[i++] = ++len;
            } 
            else if (len > 0) {
                len = lps[len - 1];
            } 
            else {
                lps[i++] = 0;
            }
        }
        for (int i = 0, j = 0; i < 2 * m - 1; ) {
            int value = a[i % m];

            if (value == b[j]) {
                i++;
                j++;

                if (j == m) return true;
            } 
            else if (j > 0) {
                j = lps[j - 1];
            } 
            else {
                i++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int i = 0; i < n; i += k) {
                vector<int> a(nums.begin() + i, nums.begin() + i + k);

                vector<int> b(sorted.begin() + i, sorted.begin() + i + k);

                if (!isRotation(a, b)) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};
