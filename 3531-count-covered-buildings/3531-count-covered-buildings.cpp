const int maxn = 1e5 + 5;
#define fi first
#define se second

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int cnt[maxn];
        memset(cnt, 0, sizeof cnt);

        vector <pair <int, int>> x[maxn], y[maxn];
        for(int i = 0; i < buildings.size(); ++i){
            auto p = buildings[i];
            x[p[0]].emplace_back(p[1], i);
            y[p[1]].emplace_back(p[0], i);
        }
        for(int i = 0; i < maxn; ++i){
            if(x[i].size() < 3) continue;
            sort(x[i].begin(), x[i].end());
            for(int j = 1; j < x[i].size()-1; ++j){
                cnt[x[i][j].se]++;    
            }
        }
        int sz = 0;
        for(int i = 0; i < maxn; ++i){
            if(y[i].size() < 3) continue;
            sort(y[i].begin(), y[i].end());
            for(int j = 1; j < y[i].size()-1; ++j){
                sz += cnt[y[i][j].se];    
            }
        }
        return sz;
    }
};