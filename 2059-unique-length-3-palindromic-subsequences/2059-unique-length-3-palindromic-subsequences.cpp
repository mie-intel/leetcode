class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for(char a = 'a'; a <= 'z'; ++a){
            int l = 0;
            int r = s.length() - 1;
            while(l < s.length() && s[l] != a) l++;
            while(r > -1 && s[r] != a) r--;
            set <int> st;
            for(int i = l + 1; i < r; ++i) st.insert(s[i]);
            ans += st.size();
        }
        return ans;
    }
};