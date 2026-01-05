class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        long long res = 0;
        long long smallest = LLONG_MAX;
        for(auto p : matrix){
            for(auto q : p){
                smallest = min(smallest, (long long)abs(q));
                neg += q < 0;
                res += abs(q);
            }
        }
        if(neg % 2 == 1) res -= smallest + smallest;
        return res;
    }
};