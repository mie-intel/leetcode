typedef long long ll;

ll cnt(ll x){
    return (x * (x + 1) / 2);
}

class Solution {
public:
    ll ans = 0;
    long long getDescentPeriods(vector<int>& prices) {
        ans = 0;
        ll sz = 1;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] == prices[i-1]-1) sz++;
            else{
                ans += cnt(sz);
                sz = 1;
            }
        }
        ans += cnt(sz);
        return ans;
    }
};