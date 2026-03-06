class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        cnt += (s[0] == '1');
        for(int i = 1; i < s.length(); ++i){
            cnt += (s[i] == '1' && s[i-1] == '0');
        }
        return cnt == 1;
    }
};