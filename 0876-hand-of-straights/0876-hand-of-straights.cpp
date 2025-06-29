class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      if(hand.size()%groupSize!=0) return false;
      map<int,int>mp;
      for(auto it:hand){
        mp[it]++;
      }

      for(auto it:mp){
        int start=it.first;  // element
        int count=it.second;  // freq
         if(count>0){
           for(int i=0;i<groupSize;i++){
             if(mp[start+i] <count ) return false;
             mp[start+i]-=count;
           }
         }
      }
      return true;
    }
};