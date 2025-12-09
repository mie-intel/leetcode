typedef long long ll;

const int maxn = 1e5 + 3;
const ll mod = 1e9 + 7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        vector <ll> mp[maxn];
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }
        ll ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            int kal = nums[i] * 2;
            if(kal >= maxn) continue;
            int id = lower_bound(mp[kal].begin(), mp[kal].end(), i) - mp[kal].begin();
            if(id == mp[kal].size()) continue;
            if(kal == nums[i]){
                ll up = mp[kal].size() - id - 1;
                ll low = id;
                ans += (up * low % mod);
            }
            else{
                ll up = mp[kal].size() - id;
                ll low = id;
                ans += (up * low % mod);
            }
            ans %= mod;
        }
        return ans;
    }
};