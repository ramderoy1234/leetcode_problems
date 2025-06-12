class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else if(c==']' || c=='}' || c==')'){
                if(st.empty()) return false;
                else if( st.top()=='(' && c==')' || st.top()=='{' && c=='}' || st.top()=='[' && c==']' ){
                    st.pop();
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};