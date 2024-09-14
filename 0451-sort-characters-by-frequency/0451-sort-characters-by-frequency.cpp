class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        string ans = "";
        priority_queue<pair<int, char>> pq;

        for(auto c:mp){
          pq.push({c.second,c.first});
        }

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
