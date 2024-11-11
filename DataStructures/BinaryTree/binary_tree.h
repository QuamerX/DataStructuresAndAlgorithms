#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* create_node(int data);

// Function to insert a value in the binary tree
TreeNode* insert(TreeNode* root, int data);

// Function to search for a value in the binary tree
TreeNode* search(TreeNode* root, int data);

// Function to find the minimum value in the binary tree
TreeNode* find_min(TreeNode* root);

// Function to delete a node from the binary tree
TreeNode* delete_node(TreeNode* root, int data);

// Function to perform an in-order traversal of the tree
void in_order_traversal(TreeNode* root);

// Function to free the entire binary tree
void free_tree(TreeNode* root);

#endif // BINARY_TREE_H

