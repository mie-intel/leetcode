class Solution {
public:
    bool sho(string A, string B){
        if(A.length() != B.length()) return A.length() < B.length();
        for(int i = 0; i < A.length(); ++i){
            if(A[i] != B[i]) return A[i] < B[i];
        }
        return true;
    }
    string shortestBeautifulSubstring(string s, int k) {
        string tmp = "";
        // for(int i = 0; i < s.length(); ++i) tmp += "%";
        for(int i = 0; i < s.length(); ++i){
            string t = "";
            int c = 0;
            int j = i;
            while(c < k && j < s.length()){
                t += s[j];
                if(s[j] == '1') c++;
                j++;
            }
            if(c < k) continue;
            if(tmp == "" || sho(t, tmp)) tmp = t;
        }
        if(tmp[0] == '%') return "";
        return tmp;
    }
};