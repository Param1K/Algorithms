#include<stdio.h>
#include<stdlib.h>

typedef struct treenode TreeNode;
struct treenode {
    //char data[40];
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

void *insert(TreeNode **root, TreeNode *new)
{
    if(*root == NULL) {
        *root = new;
        printf(", inserted node %d\n", new->item);
    } else if ((*root)->item > new->item) {
        printf(",left");
        insert(&(*root)->left, new);
    } else {
        printf(",right");
        insert(&(*root)->right, new);
    }
    return;
}

int cleanup (TreeNode **root) 
{
    if(!(*root)) {
        return 1;
    }
    if ((*root)->left != NULL) {
        if (cleanup(&(*root)->left)){
            (*root)->left = NULL;
        }
    }
    if ((*root)->right != NULL) {
        if(cleanup(&(*root)->right)) {
            (*root)->right = NULL;
        }
    }
    if(((*root)-> left == NULL) && ((*root)->right == NULL)) {
        printf(" deleting tree node %d\n", (*root)->item);
        free(*root);
        return 1;
    }
    return 0;
}

void traverse_cleanup(TreeNode **root) 
{
    if(*root) {
        TreeNode *left = (*root)->left, *right = (*root)->right;
        printf("cleaning %d\n",(*root)->item);
        free(*root);
        traverse_cleanup(&left);
        traverse_cleanup(&right);
    }
}

void traverse_inorder(TreeNode **root) 
{
    if(*root) {
        traverse_inorder(&(*root)->left);
        printf("Visiting %d\n",(*root)->item);
        traverse_inorder(&(*root)->right);
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
#if 0
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
#endif

TreeNode **search_node(TreeNode **node, int item)
{
    if (!(*node)) {
        printf("node not fuond");
        return NULL;
    } else if (item < (*node)->item) {
        node = search_node(&(*node)->left, item);
    } else if (item > (*node)->item) {
        node = search_node(&(*node)->right, item);
    }
    return node;
}

void delete_node (TreeNode **root, int item)
{
    TreeNode **pos = NULL;
    TreeNode *q = NULL;
    TreeNode *r = NULL;
    pos = search_node(root, item);
    r = *pos;
    if(!(*pos)) {
        printf("Tried to delete non existing node");
    } else if ((*pos)->left == NULL) {
        *pos = (*pos)->right;
        free(r);
    } else if ((*pos)->right == NULL) {
        *pos = (*pos)->left;
        free(r);
    } else {
        for(q = (*pos)->right; q->left; q = q->left);
        q->left = (*pos)->left;
        *pos = (*pos)->right;
        free(r); 
    }
}

void main(void) 
{
    TreeNode *root = NULL;
    TreeNode *new = NULL;    
    int count = 0;
    int elem[10] = {4,8,9,3,2,6,7,5,1,0};

    while(count < 10) {
        new = create_node(elem[count++]);
        insert(&root, new);
    }

    traverse_inorder(&root);
    printf("\n delete node 3\n");
    search_n_del(root, 3);
    traverse_inorder(&root);
    printf("\n delete node 8\n");
    delete_node(&root, 8);
    traverse_inorder(&root);
    printf("current root %d\n",root->item);
    //traverse_cleanup(&root);
    //printf("current root %d\n",root->item);
    cleanup(&root);    
}
