typedef long long ll;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        ll sum = 0;
        for(auto p : b) sum += p;
        sort(b.rbegin(), b.rend());
        auto cek = [&](ll m) -> bool{
            ll sisa = 0;
            ll cnt = 0;
            for(auto p : b){
                if(p >= m){
                    cnt++;
                    continue;
                }
                else{
                    sisa += p;
                    if(sisa >= m){
                        sisa %= m;
                        cnt++;
                    }
                }
            }
            return cnt >= n;
        };
        ll ans = 0;
        ll l = 1, r = sum;
        while(l <= r){
            ll m = (l + r)/2;
            if(cek(m)){
                ans = max(ans, m);
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return ans;
    }
};