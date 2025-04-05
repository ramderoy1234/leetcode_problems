class BSTIterator {
stack<TreeNode*> mystack;

    void pushAll(TreeNode* root) {
        while (root != nullptr) {
            mystack.push(root);
            root = root->left; 
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = mystack.top();
        mystack.pop();
        pushAll(temp->right); 
        return temp->val;
    }
    bool hasNext() {
        return !mystack.empty();
    }
};
