class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string t = s + s;
        int h[2];
        h[0] = h[1] = 0;
        for(int i = 0; i < n - 1; ++i){
            if(t[i] == '1') h[i%2]++;
        }
        int cnt = INT_MAX;
        for(int i = n - 1; i < n + n; ++i){
            if(t[i] == '1') h[i%2]++;
            int l = i - (n - 1);
            int tmp = 0;
            if(n % 2 == 0){
                tmp = min(
                        (abs(h[0])) + (abs(h[1] - (n/2))),
                        (abs(h[0] - (n/2))) + (abs(h[1]))
                        );
            }
            else{
                if(i % 2 == 0){
                    tmp = min(
                        abs(h[0] - (0)) + abs(h[1] - (n/2)),
                        abs(h[0] - (n/2+1)) + abs(h[1] - (0))
                        );
                }
                else{
                    tmp = min(
                        abs(h[0] - 0) + abs(h[1] - (n/2+1)),
                        abs(h[0] - (n/2)) + abs(h[1] - (0))
                        );
                }
            }
            cnt = min(cnt, tmp);
            if(t[i-(n-1)] == '1')h[(i-(n-1))%2]--;
        }
        return cnt;
    }
};