class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            sum += nums[i];
        }
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < n-1; ++i){
            cnt += nums[i];
            sum -= nums[i];
            ans += (cnt - sum) % 2 == 0;
        }
        return ans;
    }
};