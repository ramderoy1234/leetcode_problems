class Solution {
public:
    int reachNumber(int target) {
       int tar=abs(target);
       int cnt=0;
       int sum=0;
       while(sum<tar || (sum-tar)%2!=0){
          cnt++;
          sum+=cnt;
       }
       return cnt;
    }
};