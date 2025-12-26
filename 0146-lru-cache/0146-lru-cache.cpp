class LRUCache {
public:
    int cap;
    int t;
    set <pair <int, int>> st;
    map <int, int> last;
    map <int, int> val;
    LRUCache(int capacity) {
        cap = capacity;
        t = 0;
    }

    int get(int key) {
        if(val.count(key)){
            t++;
            int ls = last[key];
            last[key] = t;
            st.erase(make_pair(ls, key));
            st.emplace(t, key);
            return val[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        t++;
        if(val.count(key)){
            val[key] = value;
            int ls = last[key];
            st.erase(make_pair(ls, key));
            last[key] = t;
            st.emplace(make_pair(t, key));
        }
        else if(st.size() < cap){
            val[key] = value;
            last[key] = t;
            st.emplace(t, key);
        }
        else{
            auto p = *st.begin();
            last.erase(p.second);
            val.erase(p.second);
            st.erase(st.begin());
            val[key] = value;
            last[key] = t;
            st.emplace(t, key);           
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */