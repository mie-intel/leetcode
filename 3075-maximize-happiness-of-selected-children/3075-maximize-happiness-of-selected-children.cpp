class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long sm = 0;
        long long ans = 0;
        for(auto p : happiness){
            if(k == 0) break;
            ans += max(p - sm, 0ll);
            sm++;
            k--;
        }
        return ans;
    }
};