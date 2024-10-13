class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        st.push(0);
        int ans=0;
        for(int i=1;i<h.size();i++){

            while(!st.empty() && h[st.top()]>h[i]){
                int tp=st.top();
                st.pop();
                int tempAns;
                if(st.empty()) tempAns=i*h[tp];
                else tempAns=(i-st.top()-1)*h[tp];
                
                ans=max(ans,tempAns);
            }
            st.push(i);
        }
        int l=h.size();
        // while(!st.empty()){
        //     cout<<st.top()<<endl;
        //     st.pop();
        // }
        while(!st.empty()){
            int tp=st.top();
            st.pop();
            int tempAns;
            if(st.empty()) tempAns=l*h[tp];
            else tempAns=(l-st.top()-1)*h[tp];
            ans=max(ans,tempAns);
        }
        // ans=max(ans,sm*(l+1));
        return ans;
    }
};
