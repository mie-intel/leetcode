const int maxn = 1e5 + 5;
#define fi first
#define se second

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int cnt[maxn];
        memset(cnt, 0, sizeof cnt);
        gp_hash_table <int, set <pair <int, int>>, chash> x, y;
        for(int i = 0; i < buildings.size(); ++i){
            auto p = buildings[i];
            x[p[0]].emplace(p[1], i);
            y[p[1]].emplace(p[0], i);
        }
        for(auto [q, p]: x){
            int cz = 0;
            for(auto c : p){
                if(cz > 0 && cz < p.size()-1){
                    cnt[c.se]++;    
                }
                cz++;
            }
        }
        int sz = 0;
        for(auto [q, p]: y){
            int cz = 0;
            for(auto c : p){
                if(cz > 0 && cz < p.size()-1){
                    sz += cnt[c.se];
                }
                cz++;
            }
        }
        return sz;
    }
};