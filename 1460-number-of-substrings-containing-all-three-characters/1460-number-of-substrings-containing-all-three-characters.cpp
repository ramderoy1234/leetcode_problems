class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int cnt=0;
        int n=s.size();
        unordered_map<char,int>mp;
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            while(mp['a']&&mp['b']&&mp['c']){
                mp[s[i]]--;
                cnt+=n-j;
                i++;
            }
        }
        return cnt;
    }
};


















