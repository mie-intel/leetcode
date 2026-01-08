const int maxn = 1e3 + 1;
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int dp[maxn][maxn];
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int cost = nums1[i] * nums2[j];
                int tmp = INT_MIN;
                if(i > 0) tmp = max(tmp, dp[i-1][j]);
                if(j > 0) tmp = max(tmp, dp[i][j-1]);
                int add = 0;
                if(i > 0 && j > 0) add = dp[i-1][j-1];
                dp[i][j] = max(add + cost, cost);
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
        return dp[n-1][m-1];
    }
};