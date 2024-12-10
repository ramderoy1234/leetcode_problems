class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
        int e=1000000000;
        int n=bloomDay.size();
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int adj=0;
            int bouq=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    adj++;
                    if(adj==k){
                        bouq++;
                        adj=0;
                    }
                }
                else{
                    adj=0;
                }

            }

            if(bouq>=m){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};