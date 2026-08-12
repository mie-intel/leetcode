class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map <int, int> mp;
        int r = -1;
        int ans = 0;
        for(int l = 0; l < nums.size(); ++l){
            while(r + 1 < nums.size() && mp[nums[r+1]] + 1 <= k){
                r++;
                mp[nums[r]]++;
            }
            ans = max(ans, r - l + 1);
            mp[nums[l]]--;
        }
        return ans;
    }
};