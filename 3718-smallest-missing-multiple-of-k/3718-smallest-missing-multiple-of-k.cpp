class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set <int> st = set <int>(nums.begin(), nums.end());
        for(int i = 1; i < 200; ++i){
            if(st.count(k * i)) continue;
            return k * i;
        }
        return -1;
    }
};