class Solution {
  bool palindrome(int i,int j,string &s){
    while(i<j){
      if(s[i++]!=s[j--]) return false;
    }
    return true;
  }
  void recursion(int start,string &s,vector<string>&path,vector<vector<string>>&ans){
    if(start==s.size()){
      ans.push_back(path);
      return ;
    }
    for(int i=start;i<s.size();i++){
      if(palindrome(start,i,s)){
        path.push_back(s.substr(start,i-start+1));
        recursion(i+1,s,path,ans);
        path.pop_back();
      }
    }
  }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>>ans;
        recursion(0,s,path,ans);
        return ans;
    }
};