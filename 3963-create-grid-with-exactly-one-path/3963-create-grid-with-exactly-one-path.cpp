class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        
        for (int i = 0; i < m; ++i) {
            if (i == 0) {
                grid.push_back(string(n, '.'));
            } else {
                grid.push_back(string(n - 1, '#') + ".");
            }
        }
        
        return grid;
        

    }
};