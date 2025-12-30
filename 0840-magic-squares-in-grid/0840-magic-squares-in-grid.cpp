class Solution {
public:
    bool cek(vector <vector <int>> grid, int i, int j){
        set <int> st;
        for(int a = i; a <= i + 2; a++){
            for(int b = j; b <= j + 2; b++){
                st.insert(grid[a][b]);
            }
        }
        if(st.size() != 9) return false;
        if(*st.begin() != 1) return false;
        if(*prev(st.end()) != 9) return false;
        set <int> sum;
        for(int a = i; a <= i + 2; a++){
            int sm = 0;
            for(int b = j; b <= j + 2; b++){
                sm += grid[a][b];
            }
            sum.insert(sm);
        }
        for(int b = j; b <= j + 2; b++){
            int sm = 0;
            for(int a = i; a <= i + 2; a++){
                sm += grid[a][b];
            }
            sum.insert(sm);
        }
        sum.insert(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]);
        sum.insert(grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]);
        return sum.size() == 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i + 2 < grid.size(); ++i){
            for(int j = 0; j + 2 < grid[0].size(); ++j){
                ans += cek(grid, i, j);
            }
        }
        return ans;
    }
};