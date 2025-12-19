#define fi first
#define se second
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,popcnt,lzcnt")
#include <immintrin.h>

const int maxn = 1e5 + 1;
int vis[maxn];
vector <pair <int, int>> v[maxn];
set <int> meet[maxn];
vector <int> meet2[maxn];
int pt[maxn];

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int f) {
        ios_base::sync_with_stdio(0);
        for(int i = 0; i < n; ++i){
            meet[i].clear();
            v[i].clear();
            pt[i] = 0;
            vis[i] = 0;
        }
        for(auto p : meetings){
            v[p[0]].emplace_back(p[2], p[1]);
            v[p[1]].emplace_back(p[2], p[0]);
            meet[p[2]].emplace(p[1]);
            meet[p[2]].emplace(p[0]);
        }
        for(int i = 0; i < n; ++i){
            sort(v[i].begin(), v[i].end());
        }
        vis[f] = vis[0] = 1;
        for(int t = 1; t < maxn; ++t){
            if(meet[t].empty()) continue;
            queue <int> q;
            // cout << "AT T=" << t << '\n' << " _";
            for(auto p : meet[t]){
                // cout << p << " " << vis[p] << ": ";
                if(vis[p] > 0){
                    vis[p] = 1;
                    q.push(p);
                }
            }
            // cout << '\n';
            while(!q.empty()){
                int p = q.front();
                q.pop();
                if(vis[p] == 2) continue;
                vis[p] = 2;
                // auto id = v[p][pt[p]];
                
                while(pt[p] < v[p].size()){
                    auto id = v[p][pt[p]];
                    // cout << " _" << p << " " << id.fi << " " << id.se << " " << vis[id.se] << endl;
                    if(id.fi < t) {
                        pt[p]++;
                        continue;
                    }
                    if(id.fi > t) break;
                    if(vis[id.se] > 0) {
                        pt[p]++;
                        continue;
                    }
                    vis[id.se] = 1;
                    q.push(id.se);
                    pt[p]++;
                }
            }
        }
        vector <int> res;
        for(int i = 0; i < n; ++i) if(vis[i]) res.push_back(i);
        return res;
    }
};