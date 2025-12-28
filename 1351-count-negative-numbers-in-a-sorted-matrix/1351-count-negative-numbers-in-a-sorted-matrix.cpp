class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto p : grid){
            for(auto q : p){
                ans += (q < 0);
            }
        }
        return ans;
    }
};