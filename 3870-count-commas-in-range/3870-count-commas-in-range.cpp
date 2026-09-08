class Solution {
public:
    int give(int n){
        if(n < 1000) return 0;
        if(n < 10000000) return 1;
        return 2;
    }
    int countCommas(int n) {
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += give(i);
        }
        return sum;
    }
};