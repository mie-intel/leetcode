int do_some(int x){
    for(int i = 0; i < 30; ++i){
        if((x & (1 << i)) == 0){
            return x - (1 << (i-1));
        }
    }
    return 0;
}

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector <int> v;
        for(auto p : nums){
            if(p == 2) v.push_back(-1);
            else v.push_back(do_some(p));
        }
        return v;
    }
};