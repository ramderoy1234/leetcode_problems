class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int maxi=0;
        unordered_map<char,int>mp;
        int ans=0;
        for(int j=0;j<s.size();j++){
          mp[s[j]]++;
          maxi=max(maxi,mp[s[j]]);
          while(j-i+1-maxi>k){
            mp[s[i]]--;
            i++;
          }
          ans=max(ans,j-i+1);
        }
        return ans;
    }
};