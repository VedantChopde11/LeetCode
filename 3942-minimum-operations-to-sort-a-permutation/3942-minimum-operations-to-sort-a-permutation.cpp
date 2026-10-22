#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int zeroPos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroPos = i;
                break;
            }
        }

        bool increasing = true;
        for (int i = 0; i < n; i++) {
            if (nums[(zeroPos + i) % n] != i) {
                increasing = false;
                break;
            }
        }

        bool decreasing = true;
        for (int i = 0; i < n; i++) {
            if (nums[(zeroPos - i + n) % n] != i) {
                decreasing = false;
                break;
            }
        }

        int answer = 1e9;

        if (increasing) {
            answer = min(answer, zeroPos);
            answer = min(answer, n - zeroPos + 2);
        }

        if (decreasing) {
            answer = min(answer, (zeroPos + 1) % n + 1);
            answer = min(answer, n - zeroPos);
        }

        if (answer == 1e9) return -1;

        return answer;
    }
};
