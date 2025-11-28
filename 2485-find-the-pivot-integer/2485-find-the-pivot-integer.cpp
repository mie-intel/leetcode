class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n;
        int sl = 0, sr = 0;
        while(l <= r){
            if(l == r){
                if(sl != sr) return -1;
                else return l;
            }
            else{
                if(sl < sr){
                    sl += l;
                    l++;
                }
                else{
                    sr += r;
                    r--;
                }
            }
        }
        return -1;
    }
};