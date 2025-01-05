class Solution {
public:
    int gcd(int a,int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& arr1, vector<int>& arr2) {
        int g = arr2[0];
        for(int i=0;i<arr2.size();i++){
            g = gcd(g,arr2[i]);
        }
        sort(arr1.begin(),arr1.end());
        int ans = 0;
        for(int i=0;i<arr1.size();i++){
            if(g%arr1[i] == 0) return i;
        }
        return -1;

    }
};

// 30 18
// 6
// 3 2
// 7 13
