typedef long long ll;

class Solution {
public:
    static const int maxn = 5e2 + 1;
    int pref[maxn];
    ll dp[maxn][maxn];
    int N;
    int stoneGameV(vector<int>& stoneValue) {
        memset(pref, 0, sizeof pref);
        memset(dp, 0, sizeof dp);
        N = stoneValue.size();
        for(int i = 1; i <= N; ++i){
            pref[i] = pref[i-1] + stoneValue[i-1];
        }
        
        for(int len = 2; len <= N; ++len){
            for(int i = 1; i + len - 1 <= N; ++i){
                ll sm = pref[i+len-1] - pref[i-1];
                for(int j = i; j < i + len - 1; ++j){
                    ll kiri = pref[j] - pref[i-1];
                    if(kiri == sm - kiri){
                        dp[i][i+len-1] = max(dp[i][i+len-1], dp[i][j] + kiri);
                        dp[i][i+len-1] = max(dp[i][i+len-1], dp[j+1][i+len-1] + sm - kiri);
                    }
                    else if(kiri < sm - kiri){
                        dp[i][i+len-1] = max(dp[i][i+len-1], dp[i][j] + kiri);
                    }
                    else{
                        dp[i][i+len-1] = max(dp[i][i+len-1], dp[j+1][i+len-1] + sm - kiri);
                    }
                }
            }
        }
        return dp[1][N];
    }
};