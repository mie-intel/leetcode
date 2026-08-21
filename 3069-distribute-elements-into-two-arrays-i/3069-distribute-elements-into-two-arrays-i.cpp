class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector <int> A, B;
        for(int i = 0; i < nums.size(); ++i){
            if(A.empty()) A.push_back(nums[i]);
            else if(B.empty()) B.push_back(nums[i]);
            else{
                if(A.back() > B.back()) A.push_back(nums[i]);
                else B.push_back(nums[i]);
            }
        }
        for(auto p : B) A.push_back(p);
        return A;
    }
};