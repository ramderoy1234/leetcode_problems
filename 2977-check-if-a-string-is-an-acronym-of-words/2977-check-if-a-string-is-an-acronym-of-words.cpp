class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(string &word:words){
            ans+=word[0];
        }
        return ans==s;
    }
};