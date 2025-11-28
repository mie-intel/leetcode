typedef long long ll;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, ll target) {
        sort(num.begin(), num.end());
        vector <ll> nums = vector <ll> (num.begin(), num.end());
        set <vector <ll>> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                for(int k = j+1; k < n; ++k){
                    ll p = nums[i] + nums[j] + nums[k];
                    if(binary_search(nums.begin() + k+1, nums.end(), target - p)){
                        res.insert({nums[i], nums[j], nums[k], target - p});
                    }
                }
            }
        }
        vector <vector <int>> r;
        for(auto p : res){
            vector <int> pp;
            for(auto q : p){
                pp.push_back(q);
            }
            r.push_back(pp);
        }
        return r;
    }
};