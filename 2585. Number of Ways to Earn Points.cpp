class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;
    unordered_map<int,unordered_map<int,bool>> check;
    int solve(vector<vector<int>>& arr,int i,int t){
        if(t == 0) return 1;
        if(t<0) return 0;
        if(i>=arr.size()) return 0;
        if(check[i][t]) return dp[i][t];
        int n = arr[i][0];
        int k = arr[i][1];
        int ans = 0;

        for(int j = 0;j<=n;j++){
            int tt = solve(arr,i+1,t-(k*j));
            ans = (ans + tt)%1000000007;
        }
        check[i][t] = true;
        return dp[i][t] = ans;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        
        return solve(types,0,target);
    }
};
