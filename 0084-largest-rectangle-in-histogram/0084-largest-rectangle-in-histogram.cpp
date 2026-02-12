class Solution {
public:
vector<int>NextsmallerElement(vector<int>&arr,int n){
  stack<int>st;
  vector<int>ans(n,n);
  for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[i]<=arr[st.top()]){
      st.pop();
    }
    if(!st.empty()) ans[i]=st.top();
    st.push(i);
  }
  return ans;
}
vector<int>PreviousSmallerElement(vector<int>&arr,int n){
  stack<int>st;
  vector<int>ans(n,-1);
  for(int i=0;i<n;i++){
    while(!st.empty() && arr[i]<arr[st.top()]){
      st.pop();
    }
    if(!st.empty()) ans[i]=st.top();
    st.push(i);
  }
  return ans;
}
    int largestRectangleArea(vector<int>& histo) {
      int n=histo.size();
      vector<int>NSE=NextsmallerElement(histo,n);
      vector<int>PSE=PreviousSmallerElement(histo,n);
      int area=INT_MIN;
      for(int i=0;i<n;i++){
        int lenght=histo[i];
        int breadth=NSE[i]-PSE[i]-1;
        int newArea=lenght*breadth;
        area=max(newArea,area);
      }
      return area;
    }
};
