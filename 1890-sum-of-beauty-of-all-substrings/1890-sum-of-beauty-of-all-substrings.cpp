class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int minFq=INT_MAX;
                int maxFq=INT_MIN;
                for(auto c:mp){
                    minFq=min(c.second,minFq);
                    maxFq=max(c.second,maxFq);
                }
                sum+=(maxFq-minFq);
            }
        }
        return sum;
    }
};