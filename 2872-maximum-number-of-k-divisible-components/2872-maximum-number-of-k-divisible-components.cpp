typedef long long ll;
class Solution {
public:
    vector <vector <int>> v;
    vector <int> val;
    int ans = 0;
    ll dfs(int a, int pr, ll k){
        ll sum = 0;
        for(auto p : v[a]){
            if(p == pr) continue;
            ll sm = dfs(p, a, k);
            if(sm % k == 0){
                ans++;
            }
            else{
                sum += sm;
            }
        }
        sum += val[a];
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        v.clear();
        val.clear();
        for(auto p : values) val.push_back(p);
        v.assign(values.size(), vector <int> ());
        for(auto p : edges){
            v[p[0]].push_back(p[1]);
            v[p[1]].push_back(p[0]);
        }
        ans = 1;
        dfs(0, -1, k);
        return ans;
    }
};