const int maxn = 1e5 + 1;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int cnt[maxn], sz[maxn];
        memset(cnt, 0, sizeof cnt);
        memset(sz, 0, sizeof sz);
        for(int i = 1; i < maxn; ++i){
            for(int j = i; j < maxn; j += i){
                cnt[j]++;
                sz[j] += i;
            }
        }
        int sm = 0;
        for(auto p : nums){
            if(cnt[p] == 4) {
                sm += sz[p];
            }
        }
        return sm;
    }
};