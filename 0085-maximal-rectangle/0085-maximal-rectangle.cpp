class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector <int>> v = vector <vector <int>>(n+2, vector <int> (m+2, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                v[i][j] = v[i][j-1] + v[i-1][j] - v[i-1][j-1] + (matrix[i-1][j-1] == '1');
            }
        }
        auto query = [&](int i, int j, int k, int l){
            return v[k][l] - v[i-1][l] - v[k][j-1] + v[i-1][j-1];
        };
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                for(int k = i; k <= n; ++k){
                    if(query(i, j, k, j) != (k - i + 1)) break;
                    // cari terkanan
                    int l = j, r = m, mid;
                    while(l <= r){
                        mid = (l + r)/2;
                        if(query(i, j, k, mid) == (k-i+1)*(mid-j+1)){
                            ans = max(ans, (k-i+1)*(mid-j+1));
                            l = mid + 1;
                        }
                        else{
                            r = mid - 1;
                        }
                    } 
                }
            }
        }
        return ans;
    }
};