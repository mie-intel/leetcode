class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector <bool> ans;
        int p = 0;
        for(int i = 0; i < nums.size(); ++i){
            p *= 2;
            p += (nums[i]);
            p %= 10;
            ans.push_back(p == 0 || p == 5);
        }
        return ans;
    }
};