class Solution {
public:

    bool cekCode(string s){
        if(s.length() == 0) return false;
        for(auto c : s){
            if(('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == '_')
                continue;
            else
                return false;
        }
        return true;
    }
    bool cekBus(string s){
        vector <string> valid = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(auto p : valid){
            if(p == s) return true;
        }
        return false;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector <array <string, 2>> v;
        for(int i = 0; i < code.size(); ++i){
            if(isActive[i] && cekCode(code[i]) && cekBus(businessLine[i])){
                v.push_back({businessLine[i], code[i]});
            }
        }
        sort(v.begin(), v.end());
        vector <string> res;
        for(auto p : v){
            res.push_back(p[1]);
        }
        return res;
    }
};