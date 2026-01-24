typedef long long ll;
#define fi first
#define se second
#define mp make_pair

class Solution {
public:
    int minimumPairRemoval(vector<int>& nm) {
        set <pair <ll, ll>> st;
        // index dan sum
        priority_queue <pair <ll, pair <pair <ll, ll>, pair <ll, ll>>>> pq;
        int sz = 0;
        st.emplace(0, nm[0]);
        for(int i = 1; i < nm.size(); ++i){
            pq.emplace(-(nm[i] + nm[i-1]), mp(mp(-(i-1), -i), mp(-nm[i-1], -nm[i])));
            st.emplace(i, nm[i]);
            if(nm[i] >= nm[i-1]) sz++;
        }
        auto exist = [&](long long id, long long sm) -> bool{
            auto p = st.lower_bound(make_pair(id, sm));
            return (p != st.end()) && p->fi == id && p->se == sm;
        };
        auto rm = [&](long long id, long long sm) ->void {
            auto p = st.lower_bound(make_pair(id, sm));
            if(p != st.begin() && p->se >= prev(p)->se) sz--;
            if(next(p) != st.end() && next(p)->se >= p->se) sz--;
            if(next(p) != st.end() && p != st.begin() && next(p)->se >= prev(p)->se) sz++;
            // cout << "RM " << id << " " << sm << " " << sz << '\n';
            st.erase(p);
        };
        auto add = [&](ll sm, int id)->void{
            // cout << "ENTERING ADD " << sm << " " << id << '\n';
            st.emplace(id, sm);
            auto p = st.lower_bound(make_pair(id, sm));
            
            // cout << "MID ADD " << sm << " " << id << '\n';
            if(next(p) != st.end() && p != st.begin() && next(p)->se >= prev(p)->se) sz--;
            if(next(p) != st.end() && sm <= next(p)->se) sz++;
            if(p != st.begin() && prev(p)->se <= sm) sz++;
            if(next(p) != st.end()){
                pq.emplace(-(sm + next(p)->se), mp(mp(-id, -next(p)->fi), mp(-sm, -next(p)->se)));
            }
            if(p != st.begin()){
                auto q = prev(p);
                pq.emplace(-(sm + q->se), mp(mp(-q->fi, -id), mp(-q->se, -sm)));
            }
            // if(pq.size()){
            //     cout << pq.top().fi << " " << pq.top().se.fi.fi << " " << pq.top().se.fi.se << '\n';
            // }
        };
        int cnt = 0;
        while(!pq.empty() && sz + 1 != st.size()){
            // cout << "SZ " << sz << " ";
            // cout << "BEF ";
            // for(auto p : st) {
            //     cout << "{" << p.fi << " " << p.se << "} ";
            // }
            // cout << '\n';
            auto p = pq.top();
            pq.pop();
            // if(st.size() < 5) cout << "" << sz << "|"  << -p.fi << "|" << -p.se.fi.fi << "|" << -p.se.fi.se << '\n';
            // if(st.size() < 5) cout << "" << sz << "|"  << "|" << -p.se.se.fi << "|" << -p.se.se.se << '\n';
            if(!exist(-p.se.fi.fi, -p.se.se.fi) || !exist(-p.se.fi.se, -p.se.se.se)) continue;
            // if(st.size()<5)cout << "DO\n";
            rm(-p.se.fi.fi, -p.se.se.fi);
            rm(-p.se.fi.se, -p.se.se.se);
            
            // cout << "SZ " << sz;
            // cout << " MID ";
            // for(auto p : st) {
            //     cout << "{" << p.fi << " " << p.se << "} ";
            // }
            // cout << '\n';
            // cout << "SELECTED -> | "  << -p.fi << " | " << -p.se.fi.fi << " | " << -p.se.fi.se << '\n';
            
            add(-p.fi, -p.se.fi.fi);
            cnt++;

        }
            // cout << "SZ " << sz << " AFT ";
            // for(auto p : st) {
            //     cout << "{" << p.fi << " " << p.se << "} ";
            // }
            // cout << '\n';
        return cnt;
    }
};