class Solution {
public:
    int numberOfSubstrings(string s) {
       int i=0;
       int cnt=0;
       unordered_map<char,int>mp;
       int n=s.size();
       for(int j=0;j<s.size();j++){
         mp[s[j]]++;
         while(mp['a'] && mp['b'] && mp['c']){
            mp[s[i]]--;
            cnt+=n-j;
            i++;
         }
       }
       return cnt;
    }
};













