class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int missCnt=0;
       int curr=1;
       int idx=0;
       while(missCnt<k){
         if(idx >=arr.size() || arr[idx]!=curr){
            missCnt++;
            if(missCnt==k){
                return curr;  // return when we reach the kth missing number
            }
         }
         else{
            idx++; // if current is present in array, move to next index
         }
         curr++;  // move to the next number to check
       }
       return -1;
    }
};
