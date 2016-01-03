/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getTreeHeight(TreeNode* root,vector<vector<int>> &ans){
    if(root == NULL) return 0;
    queue<TreeNode *> que;
    que.push(root);
    int depth = 0, count;
    TreeNode *left, *right;
    while(que.empty() == false){
        vector<int> temp;
        depth++;
        count = que.size();
        for(int i = 0; i < count; i++){
            left = que.front()->left;
            if(left) que.push(left);
            right = que.front()->right;
            if(right) que.push(right);
            temp.push_back(que.front()->val);
            que.pop();
        }
        ans.push_back(temp);
    }
    return depth;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> bo_up;
        vector<vector<int>> up_bo;
        vector<int> rootval;
        if(root == NULL) return  bo_up;
        getTreeHeight(root,up_bo);
        while(!up_bo.empty()){
            bo_up.push_back(up_bo.back());
            up_bo.pop_back();
        }
        return bo_up;
    }
};