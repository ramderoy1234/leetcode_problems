class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
        int e=1e9;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            int adj=0;
            int bouq=0;
            for(int i=0;i<bloomDay.size();i++){
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