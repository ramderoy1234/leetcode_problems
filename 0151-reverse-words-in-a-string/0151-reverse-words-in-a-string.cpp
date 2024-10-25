class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            string word="";
            while(s[i]!=' ' && i<n){
                word+=s[i];
                i++;
            }
            if(!word.empty()){
                st.push(word);
            }
            
        }
        string remove="";
        while(!st.empty()){
            string top=st.top();
            remove+=top;
            st.pop();
            if(!st.empty()){
                remove+=' ';
            }
        }
        return remove;
    }
};