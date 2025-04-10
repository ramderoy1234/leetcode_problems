class Solution {
  vector<int> getNSL(vector<int>& arr, int n) {
    stack<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (st.empty()) {
        ans[i] = -1;
      } else {
        while (!st.empty() && arr[st.top()] >= arr[i]) {  
          st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
      }
      st.push(i);
    }
    return ans;
  }

  vector<int> getNSR(vector<int>& arr, int n) {
    stack<int> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      if (st.empty()) {
        ans[i] = n;
      } else {
        while (!st.empty() && arr[st.top()] > arr[i]) {  
          st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
      }
      st.push(i);
    }
    return ans;
  }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);  // Get Previous Smaller Element (PSE)
        vector<int> NSR = getNSR(arr, n);  // Get Next Smaller Element (NSE)
        
        long long sum = 0;
        const int mod = 1e9 + 7; 

        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];   // Number of subarrays ending at arr[i]
            long long right = NSR[i] - i;  // Number of subarrays starting at arr[i]
            long long totalWays = (left * right) % mod * arr[i] % mod;  // contribution
            
            sum = (sum + totalWays) % mod;  
        }

        return sum;
    }
};
