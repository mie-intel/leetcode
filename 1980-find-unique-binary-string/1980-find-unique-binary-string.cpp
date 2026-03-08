class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set <string> s = set <string>(nums.begin(), nums.end());
        int it = 0;
        int n = (int)nums.size();
        for(int i = 0; i < (1 << n); ++i){
            string p = "";
            for(int j = 0; j < n; ++j){
                if(i & (1 << j)) p += '1';
                else p += '0';
            }
            reverse(p.begin(), p.end());
            if(!s.count(p)){
                return p;
            }
        }
        return "";
    }
};