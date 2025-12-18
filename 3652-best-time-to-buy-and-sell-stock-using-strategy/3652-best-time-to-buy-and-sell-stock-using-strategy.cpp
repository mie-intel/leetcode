typedef long long ll;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector <ll> p, kal;
        p.push_back(0);
        kal.push_back(0);
        for(int i = 0; i < prices.size(); ++i){
            p.push_back(prices[i] + p.back());
            kal.push_back(prices[i] * strategy[i] + kal.back());
        }
        ll sm = kal.back();
        int l = k / 2;
        for(int i = 1; i + k - 1 <= prices.size(); ++i){
            ll add = 0;
            if(i > 1) add += kal[i-1];
            if(i + k - 1 < p.size()) add += kal.back() - kal[i+k-1];
            add += (p[i+k-1] - p[i+l-1]);
            sm = max(sm, add);
        }
        return sm;
    }
};