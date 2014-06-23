#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct treenode {
        char data;
        struct treenode *left;
        struct treenode *right;
} TreeNode;

void postorder(TreeNode *root);
TreeNode *reconstruct(int n, char pre[], char in[]);

void postorder(TreeNode *root)
{
        if (root == NULL)
                return;

        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);

        return;
}

TreeNode *reconstruct(int n, char pre[], char in[])
{
        TreeNode *current;
        int leftn;
        int rightn;

        if (n == 0)
                return NULL;

        leftn = strchr(in, pre[0]) - in;
        rightn = n - leftn - 1;
        current = malloc(sizeof(TreeNode));
        assert(current != NULL);
        current->data = pre[0];
        current->left = reconstruct(leftn, pre + 1, in);
        current->right = reconstruct(rightn, pre + 1 + leftn, in + leftn + 1);

        return current;
}

int main(void)
{
        unsigned int length;
        char preorder[] = {'A', 'B', 'C', 'D', 'E'};
        char inorder[] = {'C', 'B', 'D', 'A', 'E'};
        TreeNode *root;
        length = strlen(preorder);
        assert(length == strlen(inorder));
        root = reconstruct(length, preorder, inorder);
        postorder(root);
        printf("\n");

        return 0;
}
