 
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level=0;
        int maxi=INT_MIN;
        int maxLevel=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            level++;
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=nullptr)  q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }

            if(sum>maxi){
                maxi=sum;
                maxLevel=level;
            }

        }
        return maxLevel;
    }
};