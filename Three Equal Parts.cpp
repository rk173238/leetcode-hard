class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int s = 0,n=arr.size();
        for(auto c:arr){
            if(c) s++;
        }
        if(s%3 != 0) return {-1,-1};
        if(s == 0) return {0,n-1};
        int k = s/3;
        int i=0;
        int a =-1,b=-1,c=-1;
        int ss = 0;
        while(i<arr.size()){
            if(arr[i] == 1) ss++;
            if(ss == 1 && a == -1) a = i;
            if(ss == k+1 && b == -1) b = i;
            if(ss == k*2+1 && c == -1) c = i;
            i++;
        }
        // cout<<s<<endl;
        // cout<<a<<" "<<b<<" "<<c<<endl;
        while(c < arr.size()){
            if(arr[a] == arr[b] && arr[b] == arr[c]){
                a++;b++;c++;
            }else{
                return {-1,-1};
            }
        }
        return {a-1,b};

    }
};

// 1,1,1,0,0,1
// 1,0,1,0,1,1
// 1,1,1,1
