class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n;
    int gcd(int a,int b){
        if(b == 0) return 1;
        return __gcd(a,b);
    }
    int solve(int n,int i1,int i2){
        if(n==0){
            return 1;
        }
        if(dp[n][i1][i2] != -1) return dp[n][i1][i2];
        int ans =0;
        for(int j=1;j<7;j++){
            if(gcd(j,i1) == 1 && j != i1 && j != i2){
                ans = (ans + solve(n-1,j,i1))%1000000007;
            }
        }
        return dp[n][i1][i2] = ans;
    }

    int distinctSequences(int nn) {
        n = nn;
        for(int i=0;i<=n;i++){
            vector<vector<int>> t;
            for(int j=0;j<7;j++){
                t.push_back({-1,-1,-1,-1,-1,-1,-1});
            }
            dp.push_back(t);
        }
        return solve(n,0,0);

    }
};
