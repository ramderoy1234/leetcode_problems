class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
       int cnt=0;
       for(int i=left;i<=right;i++){
         string first=words[i];
         int m=first.size();
         if(first[0]=='a' || first[0]=='e' ||first[0]=='i' || first[0]=='o'|| first[0]=='u'){
            if(first[m-1]=='a' || first[m-1]=='e'|| first[m-1]=='i' || first[m-1]=='o'|| first[m-1]=='u'){
              cnt++;
            }
         }
       }
       return cnt;
    }
};