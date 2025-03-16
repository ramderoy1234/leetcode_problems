class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
          if(words[(startIndex+i)%n]==target){
             mini=min(mini,i);
          }
          if(words[(startIndex-i+n)%n]==target){
            mini=min(mini,i);
          }
        }
       return (mini==INT_MAX)?-1:mini;
    }
};