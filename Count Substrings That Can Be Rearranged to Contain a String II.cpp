class Solution {
public:
    bool valid(vector<int>& arr1,vector<int>& arr2){
        
        for(int i=0;i<26;i++){
            if(arr2[i]>arr1[i]) return false;
        }
        return true;
    }
    long long validSubstringCount(string s1, string s2) {
        long long int i=0,j=0,ans=0;
        if(s2.size()==1){
            for(int j=0;j<s1.size();j++){
                if(s1[j] == s2[0]) ans+= s1.size()-j;
            }
            return ans;
        }
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(auto c:s2) arr2[c-'a']++;

        
        while(j<s1.size()){
            bool check = true;
            while(j<s1.size()){
                // cout<<j<<endl;
                arr1[s1[j]-'a']++;
                j++;
                if(valid(arr1,arr2)){
                    check = false;
                    break;
                }
            }
            ans += s1.size()-j+1;
            if(check){
                ans--;
                break;
            }
            // cout<<i<<" "<<j<<endl;
            while(i<s1.size() && i<j){
                // cout<<i<<endl;
                arr1[s1[i]-'a']--;
                i++;
                
                if(!valid(arr1,arr2)) break;
                ans += s1.size()-j+1;
            }
        }

        return ans;

    }
};

// abac

// a

// 4
// 3
