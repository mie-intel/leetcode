typedef long long ll;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map <ll, ll> ls;
        ls[0] = -1;
        ll sm = 0;
        ll ans = INT_MAX;
        ll total = 0;
        for(auto p : nums) total += p;
        total %= p;
        for(int i = 0; i < nums.size(); ++i){
            sm += nums[i];
            sm %= p;
            ls[sm] = i;
            ll tar = (sm - total + p + p) % p;
            if(ls.count(tar)){
                ans = min(ans, i - ls[tar]);
            }
        }
        return ans >= nums.size() ? -1 : ans;
    }
};