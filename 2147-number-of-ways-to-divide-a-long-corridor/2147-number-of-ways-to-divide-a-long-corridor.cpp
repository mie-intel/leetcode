typedef long long ll;

class Solution {
public:
    int numberOfWays(string s) {
        int c = 0;
        for(auto p : s) c += p == 'S';
        if(c % 2 == 1 || c < 2) return 0;
        int l = -1, cp = 0, cs = 0;
        ll ans = 1;
        for(int i = 0; i < s.length(); ++i){
            auto p = s[i];
            if(p == 'S'){
                cs++;
            }
            else{
                cp++;
            }
            const ll mod = 1e9 + 7;
            if(cs % 2 == 1 && p == 'S'){
                if(l != -1){
                    ans *= (cp + 1);
                    ans %= mod;
                }
                l = i;
            }
            if(p == 'S') cp = 0;
        }
        return ans;
    }
};