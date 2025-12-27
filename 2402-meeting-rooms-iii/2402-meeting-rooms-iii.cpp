typedef long long ll;
#define fi first
#define se second
const int maxn = 101;
int cnt[maxn];
bitset <maxn> vis;
int N;
// used rooms (end, index)
set <pair <ll, ll>> room;
// array of task (start, end)
set <pair <ll, ll>> pending;

pair <ll, ll> get_smallest(){
    return *room.begin();
}

void pop_room(){
    if(room.size()){
        auto p = get_smallest();
        room.erase(room.begin());
        vis[p.se] = 0;
    }
}

void add(ll start, ll end){
    if(room.size() < N){
        for(int i = 1; i <= N; ++i){
            if(!vis[i]) {
                vis[i] = 1;
                cnt[i]++;
                room.emplace(end-1, i);
                break;
            }
        }
    }
    else{
        pair <ll, ll> p = get_smallest();
        pop_room();
        room.emplace(p.fi + end - start, p.se);
        cnt[p.se]++;
    }
}

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        memset(cnt, 0, sizeof cnt);
        vis = 0;
        N = n;
        room.clear();
        pending.clear();
        for(auto p : meetings){
            pending.emplace(p[0], p[1]);
        }
        for(auto p : pending){
            while(room.size() && get_smallest().fi < p.fi) pop_room();
            add(p.fi, p.se);
        }
        int ans = 0;
        int mx = -1;
        for(int i = 1; i <= n; ++i){
            if(cnt[i] > mx){
                mx = cnt[i];
                ans = i;
            }
        }
        return ans - 1;
    }
};