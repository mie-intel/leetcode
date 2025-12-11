const int maxn = 1e5 + 5;
#define fi first
#define se second

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int cnt[maxn];
        memset(cnt, 0, sizeof cnt);
        unordered_map <int, set <pair <int, int>>> x, y;
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