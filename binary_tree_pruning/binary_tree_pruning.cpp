#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
    containsOne(root);
    return root;
  }

  bool containsOne(TreeNode* root)
  {
    if (root->left)
    {
      if (!containsOne(root->left))
      {
        root->left = nullptr;
      }
    }

    if (root->right)
    {
      if (!containsOne(root->right))
      {
        root->right = nullptr;
      }
    }

    if (!root->left && !root->right)
    {
      return root->val == 1;
    }

    return true;
  }
};

int main()
{

}