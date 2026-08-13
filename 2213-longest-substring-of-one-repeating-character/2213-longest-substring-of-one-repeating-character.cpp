class Solution {
public:
    string s;
    int N = 1;
    struct node{
        int ll, rr, mx, ln;
        char l, r;
        node(char c = '~'){
            ll = rr = mx = ln = 1;
            l = r = c;
        }  
    };

    static const int maxn = 1e5 + 1;
    node seg[4 * maxn];
    
    inline node merge(node a, node b){
        node res;
        res.l = a.l; res.r = b.r;
        res.ln = a.ln + b.ln;
        res.ll = max(res.ll, a.ll);
        if(a.ll == a.ln && b.l == a.r) res.ll = max(res.ll, a.ll + b.ll);
        res.rr = max(res.rr, b.rr);
        if(b.rr == b.ln && b.l == a.r) res.rr = max(res.rr, a.rr + b.rr);
        res.mx = max(res.rr, res.ll);
        res.mx = max(res.mx, max(a.mx, b.mx));
        if(a.r == b.l) res.mx = max(res.mx, a.rr + b.ll);
        return res;
    }

    inline void build(int l, int r, int v){
        if(l == r){
            seg[v] = node(s[l]);
        }
        else{
            int m = (l + r)/2;
            build(l, m, 2 * v);
            build(m + 1, r, 2 * v + 1);
            seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
        }
    }

    inline int update(int l, int r, int v, int pos, char c){
        if(l == r){
            seg[v] = node(c);
        }
        else{
            int m = (l + r)/2;
            if(pos <= m) update(l, m, 2 * v, pos, c);
            else update(m + 1, r, 2 * v + 1, pos, c);
            seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
        }
        return seg[v].mx;
    }

    vector<int> longestRepeating(string _s, string queryCharacters, vector<int>& queryIndices) {
        s = _s;
        N = s.length();
        build(0, N-1, 1);
        vector <int> ans;
        for(int i = 0; i < queryIndices.size(); ++i){
            ans.push_back(update(0, N-1, 1, queryIndices[i], queryCharacters[i]));
        }
        return ans;
    }
};