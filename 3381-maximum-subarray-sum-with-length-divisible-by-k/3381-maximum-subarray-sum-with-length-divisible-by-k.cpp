typedef long long ll;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector <ll> pref = {0};
        for(auto p : nums){
            pref.push_back(pref.back() + p);
        }
        int n = nums.size();
        ll mx = -1e15;
        vector <ll> dp = vector <ll> (n+1, -1e15);
        for(int i = k; i <= n; ++i){
            dp[i] = max(dp[i], dp[i-k] + pref[i] - pref[i-k]);
            dp[i] = max(dp[i], pref[i] - pref[i-k]);
            mx = max(mx, dp[i]);
        }
        for(auto p : dp){
            cout << p << " ";
        }
        cout << '\n';
        return mx;
    }
};