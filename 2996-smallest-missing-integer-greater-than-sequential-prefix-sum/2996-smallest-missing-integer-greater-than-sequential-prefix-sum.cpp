class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        bool aman = 1;
        for(int i = 1; i < nums.size() && aman; ++i){
            if(nums[i] == nums[i-1]+1) sum += nums[i];
            else aman = 0;
        }
        
        for(int i = sum; i < sum + 51; ++i){
            bool ada = 0;
            for(int j = 0; j < nums.size(); ++j){
                if(nums[j] == i){
                    ada = 1;
                    break;
                }
            }
            if(!ada) return i;
        }

        return -1;
    }
};