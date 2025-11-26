typedef long long ll;

const ll mod = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector <vector <vector <ll>>> g = vector <vector <vector <ll>>>(n, vector <vector <ll>> (m, vector <ll> (k, 0)));;        

        g[0][0][grid[0][0] % k] = 1;
        ll sum = grid[0][0] % k;
        for(int i = 1; i < n; ++i){
            sum += grid[i][0];
            sum %= k;
            g[i][0][sum] = 1;
        }
        sum = grid[0][0] % k;
        for(int i = 1; i < m; ++i){
            sum += grid[0][i];
            sum %= k;
            g[0][i][sum] = 1;
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                for(int ki = 0; ki < k; ++ki){
                    int nx = (ki + grid[i][j]) % k;
                    g[i][j][nx] += (g[i-1][j][ki] + g[i][j-1][ki]);
                    g[i][j][nx] %= mod;
                }
            }
        }
        return g[n-1][m-1][0];
    }
};