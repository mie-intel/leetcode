class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        int m = strs.size();
        bool A[m+5];
        memset(A, 0, sizeof A);
        int cnt = 0;
        bool valid = 0;
        for(int i = 0; i < n; ++i){
            bool tmp = 1;
            for(int j = 1; j < strs.size(); ++j){
                if(!A[j] && strs[j][i] < strs[j-1][i]){
                    tmp = 0;
                    break;
                }
            }
            if(tmp){
                for(int j = 1; j < strs.size(); ++j) if(!A[j]){
                    if(strs[j][i] > strs[j-1][i]){
                        A[j] = 1;
                    }
                }
            }
            cnt += (!tmp);
            int gt = 0;
            for(int j = 1; j < strs.size(); ++j) gt += A[j];
            if(gt == n-1) break;
        }
        return cnt;
    }
};