class Solution {
public:
    int nextGreaterElement(int n) {
    string s = to_string(n);
    n = s.size();
    bool ok = 0;
    for(int i = n - 1; i >= 0; i--){
         for(int j = i + 1; j < n; j++){
             if(s[j] > s[i]){
                ok = 1;
             }
         }
         if(ok){
            char x = '~';
            int p = -1;
            for(int j = i + 1; j < n; j++){
                 if(s[j] > s[i] && x > s[j]){
                    x = s[j];
                    p = j;
                 }
            }
            swap(s[p], s[i]);
            if(p < n){
            sort(s.begin() + i + 1,s.end());
            }
            break;
         }
    }
    if(ok ^ 1){
         return -1;
    }
    long long ans = 0;
    long long p = 1;
    // cout << s << '\n';
    for(int i = s.size() - 1; i >= 0; i--){
         ans += p * 1LL * (s[i] - '0');
         p *= 10;
    }
    
    if(ans > 1LL * INT_MAX){
         return -1;
    }
    return ans;
    }
};