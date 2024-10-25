
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        int mini=INT_MAX;
        vector<int>values;
        while(!q.empty()){
            int n=q.size();
        
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                q.pop();
                values.push_back(temp->val);
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            } 
        }
        sort(values.begin(),values.end());
        for(int i=1;i<values.size();i++){
            mini=min(mini,values[i]-values[i-1]);
        }
        return mini;
    }
};