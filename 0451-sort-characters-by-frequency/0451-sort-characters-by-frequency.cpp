class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto c:mp){
            pq.push({c.second,c.first});
        }
        string ans="";
        while(!pq.empty()){
            int top=pq.top().first;
            while(top--){
                ans+=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};