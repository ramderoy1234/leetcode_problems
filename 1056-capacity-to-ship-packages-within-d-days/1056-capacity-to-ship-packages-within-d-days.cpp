class Solution {
    int find(vector<int>&weights,int mid){
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+load > mid){
                load=weights[i];
                days++;
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        while(s<=e){
            int mid=s+(e-s)/2;
            int shipCap=find(weights,mid);
            if(shipCap<=days){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};