const int mod = 1e9 + 7;

vector <string> con = {"ryg", "rgy", "yrg", "ygr", "gry", "gyr",
                        "rgr", "ryr", "ygy", "yry", "grg", "gyg"};
vector <vector <int>> st;

inline void md(int &a){
    a = (a >= mod ? a - mod : a);
}

int dp[2][12];

class Solution {
public:
    
    int numOfWays(int n) {
        int ans = 0;
        if(st.empty()){
            st.resize(12);
            for(int j = 0; j < 12; ++j){
                for(int k = 0; k < 12; ++k){
                    bool valid = 1;
                    for(int l = 0; l < 3 && valid; ++l){
                        if(con[j][l] == con[k][l]) 
                            valid = 0;
                    }
                    if(valid) st[j].push_back(k);
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