class Solution {
    bool palindrome(int i,int j,string s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void recursion(int st,string s,vector<string>&path,vector<vector<string>>&ans){
        if(st==s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=st;i<s.size();i++){
            if(palindrome(st,i,s)){
                path.push_back(s.substr(st,i-st+1));
                recursion(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>ans;
        recursion(0,s,path,ans);
        return ans;
    }
};