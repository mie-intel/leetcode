#define ll long long

class Solution {
public:
    static const int maxn = (1 << 15) + 1;
    long long fpb(long long a, long long b){
        if(b == 0) return a;
        return fpb(b, a % b);
    }
    long long kp(long long a, long long b){
        return a / fpb(a, b) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll l = 0, r = 1e18, mid;
        ll ans = 1e18;
        ll n = coins.size();
        vector <long long> bag = {0};
        for(int i = 1; i < (1 << n); ++i){
            ll kpk = 1;
            for(int j = 0; j < n; ++j){
                if(i & (1 << j)){
                    kpk = kp(kpk, coins[j]);
                }
            }
            bag.push_back(kpk);
        }

        auto cek = [&](long long mid)->bool{
            ll sm = 0;
            for(int i = 1; i < (1 << n); ++i){
                ll kk = mid / bag[i];
                if((int(__builtin_popcount(i)) % 2) == 1) sm += kk;
                else sm -= kk;
            }
            return sm >= k;
        };

        while(l <= r){
            mid = (l + r)/2;
            if(cek(mid)){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};