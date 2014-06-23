#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct treenode {
        int data;
        struct treenode *left;
        struct treenode *right;
} TreeNode;

void inorder_bs_tree(TreeNode *root);
void preorder_bs_tree(TreeNode *root);
void postorder_bs_tree(TreeNode *root);
TreeNode *insert_bs_tree(TreeNode *root, int data);

void inorder_bs_tree(TreeNode *root)
{
        if (root == NULL)
                return;

        inorder_bs_tree(root->left);
        printf("data = %d\n", root->data);
        inorder_bs_tree(root->right);

        return;
}

void preorder_bs_tree(TreeNode *root)
{
        if (root == NULL)
                return;

        printf("data = %d\n", root->data);
        preorder_bs_tree(root->left);
        preorder_bs_tree(root->right);

        return;
}

void postorder_bs_tree(TreeNode *root)
{
        if (root == NULL)
                return;

        postorder_bs_tree(root->left);
        postorder_bs_tree(root->right);
        printf("data = %d\n", root->data);

        return;
}

TreeNode *insert_bs_tree(TreeNode *root, int data)
{
        TreeNode *current;

        /*
         * 如果加入的二元搜尋樹是空的，則以 malloc 要求一個節點，
         * 並形成一個只含一個節點的二元搜尋樹。
         */
        if (root == NULL) {
                current = malloc(sizeof(TreeNode));
                assert(current != NULL);
                current->data = data;
                current->left = NULL;
                current->right = NULL;
                return current;
        }

        /*
         * 如果加入的 data 比根節點的 data 還小，則加入左子樹。此時左子樹
         * 的根節點可能會變化，所以需要將回傳值指定成新的左子樹。
         */
        if (data < root->data)
                root->left = insert_bs_tree(root->left, data);
        else
                /*
                 * 否則即加入右子樹。此時右子樹的根節點也可能會變化，所以
                 * 需要將回傳值指定成新的右子樹。
                 */
                root->right = insert_bs_tree(root->right, data);

        return root;
}

int main(void)
{
        int i;
        int array_size = 5;
        int insert_keys[] = {4, 6, 2, 9, 5};
        TreeNode *root = NULL;

        for (i = 0; i < array_size; ++i)
                 root = insert_bs_tree(root, insert_keys[i]);

        printf("inorder\n");
        inorder_bs_tree(root);
        printf("preorder\n");
        preorder_bs_tree(root);
        printf("postorder\n");
        postorder_bs_tree(root);

        return 0;
}
