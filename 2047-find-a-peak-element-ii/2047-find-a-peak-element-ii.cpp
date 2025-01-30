class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int maxRow = 0;

            // Find the row with the maximum element in the middle column
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Check the neighbors
            // If mat[maxRow][mid] is greater than its neighbors, we have found a peak
            if ((mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1]) &&
                (mid == n - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1])) {
                return {maxRow, mid};
            }
            // If the left neighbor is larger, move left
            else if (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return {}; 
    }
};
