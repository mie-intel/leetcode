/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
 #define fi first
 #define se second
class Solution {
public:
    vector <string> rem;
    vector <pair <string, int>> fil;
    int cek(string s, string t){
        int cnt = 0;
        for(int i = 0; i < 6; ++i){
            cnt += (s[i] == t[i]);
        }
        return cnt;
    }
    void update(){
        vector <string> tmp;
        for(auto p : rem){
            bool c = true;
            for(auto q : fil){
                if(cek(q.fi, p) != q.se){
                    c = false;
                    break;
                }
            }
            if(c) tmp.push_back(p);
        }
        rem = tmp;
    }
    void add(string s, int n){
        fil.emplace_back(s, n);
    }
    void findSecretWord(vector<string>& words, Master& master) {
        rem.clear();
        for(auto p : words) rem.push_back(p);
        sort(rem.begin(), rem.end());
        random_shuffle(rem.begin(), rem.end());
        set <string> called;
        for(int i = 0; i < 30; ++i){
            for(auto p : rem){
                if(!called.count(p)){
                    int cnt = master.guess(rem[0]);
                    add(rem[0], cnt);
                    update();
                    called.insert(p);
                    break;
                }
            }
        }   
    }
};