/*
You are given the root of a binary tree where each node has a value 0 or 1.
Each root-to-leaf path represents a binary number starting with the most significant bit.
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary,
which is 13. For all leaves in the tree, consider the numbers represented by the path
from the root to that leaf. Return the sum of these numbers.
The test cases are generated so that the answer fits in a 32-bits integer.

Example 1:
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Example 2:
Input: root = [0]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.
*/

#include <iostream>
#include <vector>

// Tree Structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// global vector to store all numbers
std::vector<int> nums;
int num = 0;

void getNums(TreeNode* root) {
    if(root->val) {
        num <<= 1; num += 1;
    } else num <<= 1;

    if(root->left) getNums(root->left);
    if(root->right) getNums(root->right);
    if(root->left == nullptr && root->right == nullptr) nums.push_back(num);

    num>>=1;
}

int sumRootToLeaf(TreeNode* root) {
    getNums(root);
    num = 0;
    for(int n:nums) {
        num += n;
    }
    return num;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    std::cout << sumRootToLeaf(root) << std::endl;
    return 0;
}


/*
int sumRootToLeaf(TreeNode* root) {
    return DFS(root, 0);
}
int DFS(TreeNode* rt, int x) {
    if (rt == nullptr) return 0;
    x = x * 2 + rt->val;
    if (rt->left == rt->right) return x;
    return DFS(rt->left, x) + DFS(rt->right, x);
}
*/
