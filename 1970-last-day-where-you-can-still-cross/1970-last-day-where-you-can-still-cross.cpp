#define fi first
#define se second

int x[] = {0, -1, 0, 1};
int y[] = {1, 0, -1, 0};

class Solution {
public:
    bool cek(int row, int col, vector <vector <int>> cells, int m){
        vector <vector <int>> A(row, vector <int> (col, 0));
        for(int i = 0; i < m; ++i){
            A[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        vector <vector <bool>> vis(row, vector <bool> (col, 0));
        queue <pair <int, int>> q;
        for(int i = 0; i < col; ++i){
            if(!A[0][i]) {
                q.emplace(0, i);
            }
        }
        while(!q.empty()){
            pair <int, int> tp = q.front();
            q.pop();
            if(tp.fi == row-1) return true;
            if(vis[tp.fi][tp.se]) continue;
            vis[tp.fi][tp.se] = 1;
            for(int i = 0; i < 4; ++i){
                int tx = tp.fi + x[i];
                int ty = tp.se + y[i];
                if(tx < 0 || tx >= row || ty < 0 || ty >= col) continue;
                if(!A[tx][ty] && !vis[tx][ty]) q.emplace(tx, ty);
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, r = row * col, m, ans = 0;
        while(l <= r){
            m = (l + r)/2;
            if(cek(row, col, cells, m)){
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