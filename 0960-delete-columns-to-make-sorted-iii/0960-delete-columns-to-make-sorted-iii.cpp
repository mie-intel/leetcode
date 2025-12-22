class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        vector <bool> A;
        int dp[101];
        auto cek = [&](int i, int j) -> bool{
            for(int a = 0; a < n; ++a){
                if(strs[a][i] > strs[a][j]) return false;
            }
            return true;
        };
        int mx = 1;
        dp[0] = 1;
        for(int i = 1; i < m; ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if(cek(j, i)) dp[i] = max(dp[i], dp[j]+1);
            }
            mx = max(mx, dp[i]);
            cout << dp[i] << " ";
        }
        cout << '\n';
        return m - mx;
    }
};