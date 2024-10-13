class Solution {
public:
    int ans = 0;
    int solve(vector<int>& arr,int i,int n){
        int l = i-1;
        ans = 1;
        while(i<arr.size()){
            if(arr[i] > n+1){
                i--;
                break;
            }
            if(arr[i] == n){
                i++;
                n++;
                ans++;
            }
            else if(arr[i] == n-1){
                i++;
                n++;
                ans++;
            }else{
                i++;
            }
            
        }
        int r = i-1;
        return r-3;
    }
    
    int maxSelectedElements(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        // for(auto c:arr) cout<<c<<" ";
        // cout<<endl;
        int ans1 = 1;
        for(int i = 0;i<arr.size();){
            // cout<<i<<" ";
            int c1 = solve(arr,i+1,arr[i]+1);
            ans1 = max(ans1,ans);
            int c2 = solve(arr,i+1,arr[i]+2);
            
            ans1 = max(ans1,ans);
            int c = min(c1,c2);
            // cout<<c1<<" "<<c2<<" "<<c<<endl;
            if(c <= i) i++;
            else i = c;

            // cout<<i<<endl;
            
        }
        return ans1;
    }
};
