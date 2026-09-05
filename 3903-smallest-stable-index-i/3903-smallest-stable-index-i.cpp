class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        long long mx = 0;
        for(int i = 0; i < nums.size(); ++i){
            mx = max(mx, (long long)nums[i]);
            long long mn = INT_MAX;
            for(int j = i; j < nums.size(); ++j){
                mn = min(mn, (long long)nums[j]);
            }
            if(mx - mn <= k) return i;
        }
        return -1;
    }
};