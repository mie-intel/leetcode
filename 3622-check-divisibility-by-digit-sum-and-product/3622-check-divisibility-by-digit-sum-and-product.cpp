#define ll long long

class Solution {
public:
    bool checkDivisibility(long long n) {
        ll A = 1, B = 0;
        ll tmp = n;
        while(tmp > 0){
            A *= (tmp % 10);
            B += (tmp % 10);
            tmp /= 10;
        }
        return n % (A + B) == 0;
    }
};