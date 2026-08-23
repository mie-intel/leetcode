class Solution {
public:
    int get(char c){
        return c - '0';
    }
    int getA(int l){
        return l / 2 + l % 2;
    }
    int getB(int l){
        return l / 2;
    }
    bool sumGame(string num) {
        int l = 0, r = 0;
        int cl = 0, cr = 0;
        for(int i = 0; i < num.length(); ++i){
            if(i < num.length() / 2){
                if(num[i] == '?') cl++;
                else l += get(num[i]);
            }
            else{
                if(num[i] == '?') cr++;
                else r += get(num[i]);
            }
        }
        if(cl > cr){
            swap(cl, cr);
            swap(l, r);
        }
        cr -= cl;
        cl = 0;
        l -= r;
        r = 0;
        // cout << l << " " << r << " " << cl << " " << cr << '\n';
        if(l < 0) return true;
        if(9 * getA(cr) > l) return true;
        if(9 * getB(cr) < l) return true;
        return false;
    }
};