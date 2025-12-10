typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

class Solution {
public:
    ll fen[maxn];
    void upd(int pos, ll val){
        while(pos < maxn){
            fen[pos] += val;
            fen[pos] %= mod;
            pos += (pos & -pos);
        }
    }
    ll get(int pos){
        ll res = 0;
        while(pos > 0){
            res += fen[pos];
            res %= mod;
            pos -= (pos & -pos);
        }
        return res;
    }
    ll fac(ll n){
        ll res = 1;
        for(ll i = 2; i < n; ++i) res = (res * i) % mod;
        return res;
    }
    int countPermutations(vector<int>& comp) {
        int cnt = 0;
        int smaller = 0;
        for(auto p : comp){
            cnt += (p == comp[0]);
            smaller += p < comp[0];
        }
        if(cnt > 1 || smaller) return 0;
        return fac(comp.size());
    }
};