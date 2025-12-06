typedef long long ll;
const int maxn = 1e5 + 1;
ll fen[maxn];
const ll mod = 1e9 + 7;
class Solution {
public:
    multiset <int> mt;
    void clear(){
        mt.clear();
    }
    void addx(int x){
        mt.insert(x);
    }
    void erasex(int x){
        mt.erase(mt.lower_bound(x));
    }
    int sz(){
        return mt.size();
    }
    int query(){
        return (*(prev(mt.end()))) - (*(mt.begin()));
    }

    void add(ll l, ll val){
        while(l < maxn){
            fen[l] += val;
            fen[l] %= mod;
            l += (l & (-l));
        }
    }

    ll qu(ll l){
        ll res = 0;
        while(l > 0){
            res += fen[l];
            l -= (l & (-l));
            res %= mod;
        }
        return res;
    }

    ll ask(int l, int r){
        int add = 0;
        if(l == 0) add = 1;
        l = max(l, 1);
        r = max(r, 0);
        return ((qu(r) - qu(l-1) + add % mod) + mod) % mod;
    }


    int countPartitions(vector<int>& nums, int k) {
        for(int i = 0; i < maxn; ++i) fen[i] = 0;
        vector <int> n = {0};
        for(auto p : nums) n.push_back(p);
        clear();
        add(1, 1);
        addx(n[1]);
        int l = 1;
        for(int i = 2; i < n.size(); ++i){
            addx(n[i]);
            while(l < i && query() > k){
                erasex(n[l]);
                l++;
            }
            ll val = ask(l-1, i-1);
            add(i, val);
        }
        return ask(n.size()-1, n.size()-1);
    }
};