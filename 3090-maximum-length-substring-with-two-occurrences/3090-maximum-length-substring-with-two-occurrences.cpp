class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx = 0;
        for(int i = 0; i < s.length(); ++i){
            unordered_map <char, int> mp;
            for(int j = i; j < s.length(); ++j){
                mp[s[j]]++;
                if(mp[s[j]] >= 3) break;
                else mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};