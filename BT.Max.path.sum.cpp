#include<iostream> 
#include<vector> 
#include<algorithm> 

using namespace std; 

struct TreeNode{
    public: 
    int val; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};
class Solution{
public: 
   int maxSum; 
   int dfs(TreeNode* root){
     if(root==nullptr) return 0; 
     int sumLeft = max(dfs(root->left),0); 
     int sumRight = max(dfs(root->right),0); 
     maxSum = max(maxSum, root->val+sumLeft+sumRight); 
     return max(root->val+sumLeft, root->val+sumRight); 
   }
   int maxPathSum(TreeNode* root) {
     maxSum =0; 
     dfs(root); 
     return maxSum; 
   }
};

int main() {
    TreeNode* root = new TreeNode(-10); 
    root->left = new TreeNode(9); 
    root->right = new TreeNode(20); 
    root->right->left = new TreeNode(15); 
    root->right->right = new TreeNode(7); 
    Solution sol; 
    cout << sol.maxPathSum(root) <<endl; 
    return 0;
}
