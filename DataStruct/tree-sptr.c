#include<stdio.h>
#include<stdlib.h>

typedef struct treenode TreeNode;
struct treenode {
    int      item;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *create_node(int item)
{
    TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp-> item = item;
    printf("created node %d\n", item);
    return tmp;
}

int tree_empty (TreeNode *root)
{
    return ((root == NULL) ? 1 : 0);
}

TreeNode *insert(TreeNode *root, TreeNode *new)
{
    if(root == NULL) {
        printf(", inserted node %d\n", new->item);
        return new;
    } else if (root->item > new->item) {
        printf(",left");
        root->left = insert(root->left, new);
    } else {
        printf(",right");
        root->right = insert(root->right, new);
    }
    return root;
}

int cleanup (TreeNode *root) 
{
    if(!(root)) {
        return 1;
    }
    if (root->left != NULL) {
        if (cleanup(root->left)){
            root->left = NULL;
        }
    }
    if (root->right != NULL) {
        if(cleanup(root->right)) {
            root->right = NULL;
        }
    }
    if((root-> left == NULL) && (root->right == NULL)) {
        printf(" deleting tree node %d\n", root->item);
        free(root);
        return 1;
    }
    return 0;
}

int tree_height(TreeNode *root) 
{
    int lheight = 0, rheight = 0;
    if(root) {
        if (root->left != NULL) {
            lheight = tree_height(root->left);
        }
        if(root->right != NULL) {
            rheight = tree_height(root->right);
        }
        printf("visited root %d, lheight %d, rheight %d\n",
                root->item, lheight, rheight);
    } else {
        return 0;
    }
    return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
}

int level_width (TreeNode *root, int level) 
{

    int width = 0;
    if(!root) {
        return 0;
    }
    if (level == 1) {
        return 1;
    }
    width = level_width(root->left, level - 1) + level_width(root->right, level - 1);
 //   return (level_width(root->left, level - 1) + (level_width(root->right, level - 1));
    return width;
}

int tree_width(TreeNode *root) 
{
    int maxwidth = 0, width = 0;
    int height = tree_height(root);
    int i = 1;
    for(; i <= height; i++) {
        width = level_width(root, i);
        printf("width at level %d is %d\n", i, width);
        if (width > maxwidth) {
            maxwidth = width;
        }
    }
    return maxwidth;
}

void traverse_inorder(TreeNode *root) 
{
    if(root) {
        traverse_inorder(root->left);
        printf("Visiting %d\n",root->item);
        traverse_inorder(root->right);
    }
}

TreeNode *search_n_del(TreeNode *node, int item)
{
    TreeNode *p = NULL;
    TreeNode *q = NULL;
    TreeNode *r = NULL;

    if (!node) {
        printf("node not fuond");
        return NULL;
    } else if (item < node->item) {
        node->left = search_n_del(node->left, item);
    } else if (item > node->item) {
        node->right = search_n_del(node->right, item);
    } else {
        p = node;
        if (node->left == NULL) {
            node = node->right;
            free(p);
        } else if (node->right == NULL) {
            node = node->left;
            free(p);
        } else {
            for(q = node->right; q->left; q = q->left);
            q->left = node->left;
            node = node->right;
            free(p); 
        }
        return node;
    }
}

TreeNode *search_node(TreeNode *node, int item)
{
    if (!node) {
        printf("node not fuond");
        return NULL;
    } else if (item < node->item) {
        node = search_node(node->left, item);
    } else if (item > node->item) {
        node = search_node(node->right, item);
    }
    return node;
}

void main(void) 
{
    TreeNode *root = NULL;
    TreeNode *new = NULL;    
    int count = 0;
    int elem[10] = {4,8,9,3,2,6,7,5,1,0};

    while(count < 10) {
        new = create_node(elem[count++]);
        root = insert(root, new);
    }

    printf("Height of the tree is %d\n", tree_height(root));
    printf("Width of the tree is %d\n", tree_width(root));
    printf("current root %d\n",root->item);
    printf("\n delete node 3\n");
    search_n_del(root, 3);
    printf("current root %d\n",root->item);
    traverse_inorder(root);
    printf("\n delete node 8\n");
    search_n_del(root, 8);
    traverse_inorder(root);
    cleanup(root);    
}
