class Solution {
public:
    int cnt(int low){
        return low / 2 + (low % 2);
    }
    int countOdds(int low, int high) {
        return cnt(high) - cnt(max(low-1, 0));
    }
};