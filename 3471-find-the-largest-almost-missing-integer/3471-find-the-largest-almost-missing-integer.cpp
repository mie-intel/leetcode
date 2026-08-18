class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int pref[51];
        memset(pref, 0, sizeof pref);
        for(int i = 0; i+k-1 < nums.size(); ++i){
            set <int> st;
            for(int j = i; j <= i+k-1; ++j){
                if(!st.count(nums[j]))pref[nums[j]]++;
                st.insert(nums[j]);
            }
        }
        int mx = -1;
        for(int i = 0; i < 51; ++i){
            if(pref[i] == 1) mx = max(mx, i);
        }
        return mx;
    }
};