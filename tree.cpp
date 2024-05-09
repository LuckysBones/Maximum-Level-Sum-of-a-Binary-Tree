class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans=0;
        int Sum=INT_MIN;
        int level=0;

        if(root==NULL)
            return 0;

        while(!q.empty()){
            level++;
            int size = q.size();
            int loopSum=0;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                loopSum+=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                q.pop();
            }

            if(loopSum>Sum){
                Sum=loopSum;
                ans=level;
            }
        }
        return ans;
    }
};
