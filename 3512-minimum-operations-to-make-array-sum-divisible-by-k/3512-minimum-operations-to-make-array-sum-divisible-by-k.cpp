class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for(auto p : nums){
            sum += p;
        }
        return sum % k;
    }
};