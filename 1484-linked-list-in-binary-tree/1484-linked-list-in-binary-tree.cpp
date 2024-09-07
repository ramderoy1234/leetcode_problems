class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;  
        if (!root) return false;  
        if (head->val == root->val) {
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;  
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
