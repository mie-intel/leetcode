typedef long long ll;

class Solution {
public:
    ll mx(ll sum, ll A = 0, ll B = 0){
        sum -= A;
        sum -= B;
        if(sum % 3 == 0) return sum;
        return LLONG_MIN;
    }
    int maxSumDivThree(vector<int>& nums) {
        ll sum = 0;
        sort(nums.begin(), nums.end());
        vector <ll> A[3];
        for(auto p : nums){
            sum += p;
            A[p % 3].push_back(p);
        }
        ll ans = 0;
        ans = max(ans, mx(sum));
        if(A[1].size() > 0) ans = max(ans, mx(sum, A[1][0]));
        if(A[1].size() > 1) ans = max(ans, mx(sum, A[1][0], A[1][1]));
        if(A[2].size() > 0) ans = max(ans, mx(sum, A[2][0]));
        if(A[2].size() > 1) ans = max(ans, mx(sum, A[2][0], A[2][1]));
        return ans;
    }
};