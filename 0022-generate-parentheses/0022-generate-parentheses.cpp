class Solution {
  void generate(string s,int open,int close,vector<string>&ans){
    if(open==0 && close==0){
      ans.push_back(s);
    }
    if(open>0){
      generate(s+'(',open-1,close,ans);
    }
    if(close>0 && close>open){
      generate(s+')',open,close-1,ans);
    }
  }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        generate(s,n,n,ans);
        return ans;
    }
};