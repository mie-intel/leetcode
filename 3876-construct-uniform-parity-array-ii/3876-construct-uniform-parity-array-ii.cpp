class Solution {
public:
    bool ganjil(vector <int> v){
        int odd = 1e6;
        int n = v.size();
        for(int i = 0; i < n; ++i) if(v[i] % 2 == 1) odd = min(odd, v[i]);
        for(int i = 0; i < n; ++i){
            if(v[i] % 2 == 1) {
                odd = min(odd, v[i]);
                continue;
            }
            else{
                if(odd < v[i]) continue;
                else return false;
            }
        }
        return true;
    }

    bool genap(vector <int> v){
        int odd = 1e6, eve = 1e6;
        int n = v.size();
        for(int i = 0; i < n; ++i){
            if(v[i] % 2 == 0) {
                continue;
            }
            else{
                if(odd < v[i]){
                    odd = min(v[i], odd);
                    continue;
                }
                else return false;
            }
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        return ganjil(nums1) || genap(nums1);
    }
};