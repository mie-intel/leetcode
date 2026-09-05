class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        long long mx = 0;
        vector <long long> suff;
        for(int i = nums.size()-1; i >= 0; --i){
            if(suff.empty()) suff.push_back((long long)nums[i]);
            else suff.push_back(min(suff.back(), (long long)nums[i]));
        }
        for(int i = 0; i < nums.size(); ++i){
            mx = max(mx, (long long)nums[i]);
            long long mn = suff.back();
            suff.pop_back();
            if(mx - mn <= k) return i;
        }
        return -1;
    }
};