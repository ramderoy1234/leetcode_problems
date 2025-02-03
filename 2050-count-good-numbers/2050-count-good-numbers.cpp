class Solution {
const int mod=1e9+7;
private:
int powerFun(long long x,long long n){
  if(n<0){
    x=1/x;
    n=-n;
  }
  long long ans=1;
  while(n>0){
    if(n&1){
      ans=(ans*x)%mod;
      n--;
    }
    x=(x*x)%mod;
    n=n/2;
  }
  return ans;
}  
public:
    int countGoodNumbers(long long n) {
        long even=(n+1)/2;
        long odd=n/2;
        long first=powerFun(5,even)%mod;
        long second=powerFun(4,odd)%mod;

        return (first*second)%mod;
    }
};