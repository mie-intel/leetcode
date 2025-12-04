class Solution {
public:
    int countCollisions(string dir) {
        stack <char> st;
        int ans = 0;
        for(auto p : dir){
            if(st.empty()){
                if(p == 'L') continue;
                else st.push(p);
            }
            else{
                if(p == 'S'){
                    if(st.top() == 'S'){
                        while(!st.empty()) st.pop();
                        st.push(p);
                    }
                    else{
                        ans += st.size();
                        while(!st.empty()) st.pop();
                        st.push(p);
                    }
                }
                else if(p == 'L'){
                    bool run = 1;
                    while(!st.empty()){
                        if(st.top() == 'S'){
                            ans++;
                        }
                        else{
                            ans += 1 + run;
                            run = 0;
                        }
                        st.pop();
                    }
                    st.push('S');
                }
                else if(p == 'R'){
                    if(st.top() != 'R') while(!st.empty()) st.pop();
                    st.push(p);
                }
            }
        }
        return ans;
    }
};