class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int sq = sqrt(i * i + j * j);
                if(sq > n) break;
                cnt += ((sq * sq == i * i + j * j) && 1 <= sq && sq <= n);
            }
        }
        return cnt;
    }
};