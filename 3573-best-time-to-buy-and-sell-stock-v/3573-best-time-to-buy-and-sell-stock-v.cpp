typedef long long ll;

const ll maxn = 1e3 + 2;
ll dp[maxn][maxn];
// dp[1][l]

class Solution {
public:
    long long maximumProfit(vector<int>& p, int k) {
        int n = p.size();
        ll mx = 0;
        int mn = 0;
        memset(dp, 0, sizeof dp);
        for(int i = 1; i < n; ++i){
            mn = min(k, i/2+1);
            for(int c = 1; c <= mn; ++c){
                for(int j = i - 1; j >= ((c-1) * 2); --j){
                    ll add = (j ? dp[j-1][c-1] : 0);
                    dp[i][c] = max(dp[i][c], add + abs(p[j] - p[i]));
                }
                dp[i][c] = max(dp[i][c], dp[i-1][c]);
            }
        }

        for(int j = 0; j <= k; ++j){
            mx = max(dp[n-1][j], mx);
        }
        return mx;
    }
};