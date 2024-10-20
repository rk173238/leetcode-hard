class Solution {
public:
    char parseNot(string s){
        if(s == "t") return 'f';
        return 't';
    }
    char parseOr(string s){
        for(auto c:s) if(c == 't') return 't';
        return 'f';
    }
    char parseAnd(string s){
        for(auto c:s) if(c == 'f') return 'f';
        return 't';
    }
    bool parseBoolExpr(string s) {
        int i=0;
        stack<char> st;
        while(i<s.size()){
            if(s[i]== ')'){
                string tmp = "";
                while(st.top() != '('){
                    tmp = tmp + st.top();st.pop();
                }
                st.pop();
                char op = st.top();st.pop();
                if(op == '!') st.push(parseNot(tmp));
                if(op == '&') st.push(parseAnd(tmp));
                if(op == '|') st.push(parseOr(tmp));

            }else if(s[i] != ','){
                st.push(s[i]);
            }
            i++;
        }
        return st.top() == 't';
    }
};
