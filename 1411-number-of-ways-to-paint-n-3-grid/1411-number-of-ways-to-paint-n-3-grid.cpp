const long long mod = 1e9 + 7;

vector <string> con = {"ryg", "rgy", "yrg", "ygr", "gry", "gyr",
                        "rgr", "ryr", "ygy", "yry", "grg", "gyg"};

class Solution {
public:
    int numOfWays(int n) {
        long long ans = 0;
        vector <vector <long long>> dp = vector <vector <long long>> (n, vector <long long>(12, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 12; ++j){
                if(i == 0) {
                    dp[i][j] = 1;
                }
                else{
                    for(int k = 0; k < 12; ++k) {
                        bool valid = 1;
                        for(int l = 0; l < 3 && valid; ++l)
                            if(con[j][l] == con[k][l]) 
                                valid = 0;
                        if(!valid) continue;
                        (dp[i][j] += dp[i-1][k]) %= mod;
                    }
                }
            }
            if(i == n - 1){
                for(int j = 0; j < 12; ++j)
                    ans += dp[i][j];
                    ans %= mod;
            }
        }
        return ans;
    }
};