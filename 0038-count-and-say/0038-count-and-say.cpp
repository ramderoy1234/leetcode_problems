class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "";
        string res="1";

        for(int i=1;i<n;i++){
          int count=1;
          string curr="";
          for(int j=1;j<res.size();j++){
            if(res[j]==res[j-1])  count++;
            else {
                  curr+=to_string(count)+res[j-1];
                  count=1;
            }
          }
           curr += to_string(count) + res.back();
            res = curr;
        }
        return res;
    }
};