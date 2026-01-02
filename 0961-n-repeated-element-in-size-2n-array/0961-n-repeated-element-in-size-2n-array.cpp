class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        map <int, bool> v;
        for(auto p : nums){
            if(v[p]) return p;
            v[p] = 1;
        }
        return 1;
    }
};