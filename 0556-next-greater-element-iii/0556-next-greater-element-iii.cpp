class Solution {
public:
    int nextGreaterElement(int n) {
        vector<pair<int, int>> v;
        int original_n = n;
        
        while (n > 0) {
            int temp = n % 10;
            n = n / 10;
            v.push_back(std::make_pair(temp, 0));
        }
        reverse(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            v[i].second = i;
        }

        int l = v.size();
        stack<pair<int, int>> s;
        s.push(v[l - 1]);

        for (int i = v.size() - 2; i >= 0; i--) {
            
            if (v[i].first >= s.top().first) {
                s.push(v[i]);
            } else {
                int index = s.top().second;
                int value = s.top().first;
                
                while (!s.empty() && s.top().first > v[i].first) {
                    index = s.top().second;
                    value = s.top().first;
                    s.pop();
                }
                swap(v[i], v[index]);
                
                sort(v.begin() + i + 1, v.end());
                break;
            }
        }

        long long c = 0;
        for (int i = 0; i < l; i++) {
            c = c * 10 + v[i].first;
        }

        if (c > INT_MAX || c <= original_n) {
            return -1;
        }

        return c;
    }
};