
class Solution {
  TreeNode*build(vector<int>& preorder, int minVal,int maxVal,int &idx){
    if(idx>=preorder.size()) return nullptr;
    int rootVal=preorder[idx];
    if(rootVal < minVal || maxVal < rootVal ) return nullptr;

    TreeNode*root=new TreeNode(rootVal);
    idx++;
    root->left=build(preorder,minVal,rootVal-1,idx);
    root->right=build(preorder,rootVal+1,maxVal,idx);
    return root;
  }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return build(preorder,INT_MIN, INT_MAX,idx);
    }
};
