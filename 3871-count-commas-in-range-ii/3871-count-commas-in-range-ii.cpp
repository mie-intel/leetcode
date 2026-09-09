class Solution {
public:
    long long countCommas(long long n) {
        const long long l9 = 1e9;
        const long long l12 = 1e12;
        const long long l15 = 1e15;
        const long long l18 = 1e18;
        vector <long long> A = {0, 1000, 1000000, l9, l12, l15, l18};
        long long sum = 0;
        for(long long i = 1; i < 7; ++i){
            if(n >= A[i]){
                sum += (A[i] - A[i-1]) * (i-1);
            }    
            else if(n >= A[i-1]){
                sum += (n - A[i-1] + 1) * (i-1);
            }
        }
        return sum;
    }
};