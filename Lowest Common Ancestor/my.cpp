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
    TreeNode* findnode(TreeNode* node, int tar, deque<int> &que){
        if(node==NULL) return NULL;
        else if(node->val == tar){ 
            que.push_back(node->val);
            return node;
        }else if(node->val > tar){
            que.push_back(node->val);
            return findnode(node->left,tar,que);
        }else {
            que.push_back(node->val);
            return findnode(node->right,tar,que);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<int> forp;
        deque<int> forq;
        int can=0,x,y;
        //if(findnode(root, p->val, forp)==NULL && findnode(root, q->val, forq)==NULL) //[bug]this line may not run 2nd findnode()
        //    return NULL;
        if(findnode(root, p->val, forp)==NULL)return NULL;
        if(findnode(root, q->val, forq)==NULL)return NULL;
        int len = forp.size()<=forq.size()? forp.size():forq.size();
        //int len = forp.size<=forq.size? forp.size:forq.size;
        for (int i=0; i<len; i++){
            x=forp.front();
            y=forq.front();
            forp.pop_front();
            forq.pop_front();
            if(x==y) can=x;
            else break;
        }
        return findnode(root,can,forq);
    }
};