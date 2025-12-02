typedef long long ll;
#define fi first
#define se second

const ll mod = 1e9 + 7;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        ll n = points.size();
        map <int, set <int>> mp;
        for(auto p : points){
            mp[p[1]].insert(p[0]);
        }
        map <ll, ll> calc;
        ll tot = 0;
        for(auto [p, q] : mp){
            calc[p] = ((ll)q.size() * (q.size() - 1) / 2) % mod;
            tot += calc[p];
        }
        ll res = 0;
        ll sum = 0;
        for(auto [p, q] : calc){
            // cout << p << " " << q << '\n';
            sum += q;
            res += ((ll)q * (tot - sum)) % mod;
            res %= mod;
        }
        return res;
    }
};