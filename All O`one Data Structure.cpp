class AllOne {
public:
    unordered_map<string,int> mp;
    priority_queue<pair<int,string>> mx;
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> mn;

    AllOne() {
        
    }
    
    void inc(string s) {
        mp[s]++;
        if(!mx.empty() && mx.top().second == s) mx.pop();
        if(!mn.empty() && mn.top().second == s) mn.pop();
        mx.push({mp[s],s});
        mn.push({mp[s],s});
    }
    
    void dec(string s) {
        mp[s]--;
        if(mx.top().second == s) mx.pop();
        if(mn.top().second == s) mn.pop();
        if(mp[s] != 0){
            mx.push({mp[s],s});
            mn.push({mp[s],s});
        }

    }
    
    string getMaxKey() {
        
        while(!mx.empty()){
            auto c = mx.top();
            if(mp[c.second] != c.first) mx.pop();
            else break;
        }
        if(mx.empty()) return "";
        return mx.top().second;
    }
    
    string getMinKey() {
        while(!mn.empty()){
            auto c = mn.top();
            if(mp[c.second] != c.first) mn.pop();
            else break;
        }
        if(mn.empty()) return "";
        return mn.top().second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
