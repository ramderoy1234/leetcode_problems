class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q; //{t,{r,c}}
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        q.push({0,{0,0}}); // time row col

        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        while(!q.empty()){
            int time=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            if(row==n-1 && col==m-1) return time;
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int maxi=max(time,moveTime[nrow][ncol])+1;
                    if(maxi < dist[nrow][ncol]){
                        dist[nrow][ncol]= maxi;
                        q.push({maxi,{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
        
    }
};