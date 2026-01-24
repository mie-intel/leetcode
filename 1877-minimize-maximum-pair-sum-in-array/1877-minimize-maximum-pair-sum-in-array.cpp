class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        int mx = 0;
        while(l <= r){
            mx = max(mx, nums[l] + nums[r]);
            l++, r--;
        }
        return mx;
    }
};