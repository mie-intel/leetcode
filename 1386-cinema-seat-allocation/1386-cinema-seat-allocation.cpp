class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_set <int> st;
        unordered_map <int, bool> ll;
        unordered_map <int, bool> mi;
        unordered_map <int, bool> rr;
        for(int i = 0; i < r.size(); ++i){
            st.insert(r[i][0]);
            if(1 < r[i][1] && r[i][1] < 6) ll[r[i][0]] = 1;
            if(3 < r[i][1] && r[i][1] < 8) mi[r[i][0]] = 1;
            if(5 < r[i][1] && r[i][1] < 10) rr[r[i][0]] = 1;
        }
        int ans = n * 2;
        for(auto p : st){
            if(ll[p] && rr[p] && !mi[p]) ans -= 1;
            else if(ll[p] && rr[p] && mi[p]) ans -= 2;
            else if(mi[p]) ans -= int(!ll[p]) + int(!rr[p]);
            else if(int(ll[p]) + int(rr[p]) + int(mi[p]) == 1) ans--;
            cout << p << " " << ans << '\n';
        }
        return ans;
    }
};