class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                for(int k = 0; k <= n; ++k){
                    cnt += (i * i + j * j == k * k);
                }
            }
        }
        return cnt;
    }
};