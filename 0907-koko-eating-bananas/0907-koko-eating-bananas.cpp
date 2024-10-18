class Solution {
public:
    int check(vector<int>& piles, int h, int mid) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] / mid);
            // If there are leftover bananas in this pile, it takes one more hour to eat them
            if (piles[i] % mid != 0) {
                ans++; // Extra hour for the remaining bananas in the current pile
            }
        }

        return ans <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); 
        int low = 1; 
        int high = *max_element(piles.begin(), piles.end()); // Maximum possible speed (the largest pile size)

        while (low < high) {
            int mid = (low + high)/2;
            // If Koko can finish eating all bananas with speed `mid` in `h` hours
            if (check(piles, h, mid)) {
                high = mid;
            } else {
                low = mid + 1; 
            }
        }
        return low;
    }
};
