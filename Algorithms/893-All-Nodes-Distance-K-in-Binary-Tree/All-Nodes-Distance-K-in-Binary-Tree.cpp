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
    void storeParents(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue <TreeNode*>q;
        unordered_map<TreeNode* , bool> visited;
        unordered_map<TreeNode* , TreeNode*> parent_track;
        storeParents(root,parent_track);
        visited[target] = true;
        int curr_k=0;
        q.push(target);
        while(!q.empty()){
            if(curr_k == k)break;
            curr_k++;
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }

            }
        }
        vector<int>result;
        int size = q.size();
        while(size--){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};