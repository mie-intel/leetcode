class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int p = 0;
        for(auto c : nums){
            p += bool(c % 3);
        }
        return p;
    }
};