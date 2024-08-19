class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long long result = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert the digits to an integer
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // Check for overflow and underflow
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            i++;
        }

        return result * sign;
    }
};



