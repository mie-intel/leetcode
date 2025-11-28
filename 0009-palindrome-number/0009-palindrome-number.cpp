class Solution {
public:
    bool isPalindrome(int x) {
        string s = "";
        if(x < 0) return false;
        if(x == 0) return 1;
        x = abs(x);
        while(x > 0){
            s = char(x % 10 + '0') + s;
            x /= 10;
        }
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }
};