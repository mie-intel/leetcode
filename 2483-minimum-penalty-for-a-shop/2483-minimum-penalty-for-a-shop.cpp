const int maxn = 1e5 + 1;

class Solution {
public:
    int bestClosingTime(string s) {
        int pref[maxn];
        memset(pref, 0, sizeof pref);
        for(int i = 0; i < s.length(); ++i){
            pref[i] = s[i] == 'Y';
            if(i > 0) pref[i] += pref[i-1];
        }
        int ans = pref[s.length() - 1];
        int cnt = 0;
        int res = s.length();
        for(int i = s.length() - 1; i >= 0; --i){
            cnt += s[i] == 'N';
            int tmp = cnt;
            if(i > 0) tmp += pref[i-1];
            if(tmp >= ans){
                ans = tmp;
                res = i;
            }
        }
        return res;
    }
};