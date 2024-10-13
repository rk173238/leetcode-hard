class Solution {
public:

    struct node{
        int count = 0;
        node* child[26] = {};
    };

    void add(string s,node* cur){
        int i=0;
        while(i<s.size()){
            int t = s[i]-'a';
            if(cur->child[t] == NULL){
                cur->child[t] = new node();
            }
            cur->child[t]->count = cur->child[t]->count+1;
            cur= cur->child[t];
            i++;
        }

    }
    int find(string s,node* cur){
        int i=0,sum=0;
        while(i<s.size()){
            int t = s[i]-'a';
            sum += cur->child[t]->count;
            cur= cur->child[t];
            i++;
        }
        return sum;
    }

    vector<int> sumPrefixScores(vector<string>& arr) {
        node* root = new node(-1);
        vector<int> ans;
        for(auto s:arr){
            add(s,root);
        }
        for(auto s:arr){
            int t = find(s,root);
            ans.push_back(t);
        }
        return ans;
    }
};
