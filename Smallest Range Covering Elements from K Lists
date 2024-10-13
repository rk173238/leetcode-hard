class Solution {
public:
    void pqPop(priority_queue<vector<int>>& pq,unordered_map<int,int>& mp){

        auto t = pq.top();
        int arr = t[2];
        int i = t[1];
        while(mp[arr] > i){
            pq.pop();
            t = pq.top();
            arr = t[2];
            i = t[1];
        }
    }
    void getAns(vector<int>& ans,int c,int d){
        // cout<<c<<" "<<d<<endl;
        if((d-c) < (ans[1]-ans[0])){
            ans = {c,d};
        }
    }
    vector<int> smallestRange(vector<vector<int>>& arr) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        priority_queue<vector<int>> pq2;
        unordered_map<int,int> mp;
        vector<int> ans = {-100001,100001};
        int i = 0;
        for(auto c:arr){
            pq.push({c[0],0,i});
            pq2.push({c[0],0,i});
            mp[i] = 0;
            i++;
        }
        while(true){
            pqPop(pq2,mp);
            getAns(ans,pq.top()[0],pq2.top()[0]);
            auto t = pq.top(); pq.pop();
            if(t[1] == arr[t[2]].size()-1) break;
            int nextIndex = t[1]+1;
            // cout<<t[2]<<"dd"<<nt<<endl;
            pq.push({arr[t[2]][nextIndex],nextIndex,t[2]});
            pq2.push({arr[t[2]][nextIndex],nextIndex,t[2]});
            mp[t[2]] = nextIndex;
        }
        return ans;
    }
};

// 1 1 1 1
// 12
// 15
// 18
