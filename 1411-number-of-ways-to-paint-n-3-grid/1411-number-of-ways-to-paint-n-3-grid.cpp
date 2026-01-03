const int mod = 1e9 + 7;

string con[] = {"ryg", "rgy", "yrg", "ygr", "gry", "gyr",
                        "rgr", "ryr", "ygy", "yry", "grg", "gyg"};
vector <int> st[12];

inline void md(int &a){
    a = (a >= mod ? a - mod : a);
}

int dp[2][12];

class Solution {
public:
    
    int numOfWays(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int ans = 0;
        if(st[0].empty()){
            for(int j = 0; j < 12; ++j){
                for(int k = j+1; k < 12; ++k){
                    bool valid = 1;
                    for(int l = 0; l < 3; ++l){
                        if(con[j][l] == con[k][l]){
                            valid = 0;
                            break;
                        } 
                    }
                    if(valid){
                        st[j].push_back(k);
                        st[k].push_back(j);
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 12; ++j){
                if(i == 0) {
                    dp[i&1][j] = 1;
                }
                else{
                    dp[i&1][j] = 0;
                    for(int k = 0; k < st[j].size(); ++k){
                        md(dp[i&1][j] += dp[(i+1)&1][st[j][k]]);
                    }
                }
                if(i == n - 1){
                    md(ans += dp[i&1][j]);
                }
            }
        }
        return ans;
    }
};