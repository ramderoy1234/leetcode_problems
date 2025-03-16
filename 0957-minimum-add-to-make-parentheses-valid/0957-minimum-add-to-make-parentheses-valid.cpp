class Solution {
public:
    int minAddToMakeValid(string s) {
         int diffCounter = 0, ans = 0, n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            diffCounter++;
        } else if (s[i] == ')') {
            diffCounter--;
        }
        if (diffCounter < 0) {
            diffCounter++;
            ans++;
        }
    }

    return ans + diffCounter;
    }
};