class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    // Morris inorder traversal
    void morrisTraversal(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Process the current node and detect swapped nodes
                if (prev != nullptr && curr->val < prev->val) {
                    if (first == nullptr) {
                        first = prev;
                        middle = curr;
                    } else {
                        last = curr;
                    }
                }
                prev = curr;
                curr = curr->right; // Move to the right subtree
            }
            
             else {
                // Find the inorder predecessor of curr
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Make curr the right child of its inorder predecessor
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Restore the tree by removing the link between curr and its predecessor
                    pred->right = nullptr;

                    // Process the current node and detect swapped nodes
                    if (prev != nullptr && curr->val < prev->val) {
                        if (first == nullptr) {
                            first = prev;
                            middle = curr;
                        } else {
                            last = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);

        // Use Morris traversal to find swapped nodes
        morrisTraversal(root);

        // Fix the swapped nodes
        if (first && last) {
            swap(first->val, last->val);  // Non-adjacent nodes swapped
        } else if (first && middle) {
            swap(first->val, middle->val);  // Adjacent nodes swapped
        }
    }
};
