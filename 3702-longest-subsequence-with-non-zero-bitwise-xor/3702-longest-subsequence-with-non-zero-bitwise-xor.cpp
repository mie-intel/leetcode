class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sm = 0;
        bool ada = 0;
        for(int i = 0; i < nums.size(); ++i){
            sm ^= nums[i];
            if(nums[i] != 0) ada = 1;
        }
        if(sm != 0) return nums.size();
        else return (ada ? nums.size() - 1 : 0);
    }
};