typedef long long ll;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ln = min(mat.size(), mat[0].size());
        int n = mat.size();
        int m = mat[0].size();
        ll pref[302][302];
        memset(pref, 0, sizeof pref);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                for(int l = ans+1; l <= ln; ++l){
                    if(i+l-1 > n || j + l-1 > m) break;
                    ll sm = pref[i+l-1][j+l-1] - pref[i-1][j+l-1] - pref[i+l-1][j-1] + pref[i-1][j-1];
                    if(sm <= threshold){
                        ans = max(ans, l);
                    }
                }
            }
        }
        return ans;
    }
};