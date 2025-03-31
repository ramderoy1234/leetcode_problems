class Solution {
public:
    bool findPath(TreeNode* root, int target, string &path) {
        if (!root) return false;
        if (root->val == target) return true;

        path.push_back('L');
        if (findPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;

        // Find path from root to startValue and destValue
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        // Find first divergence point (LCA)
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }

        // Steps up from startValue to LCA
        string upMoves(pathToStart.size() - i, 'U');

        // Path from LCA to destValue
        string remainingMoves = pathToDest.substr(i);

        return upMoves + remainingMoves;
    }
};
