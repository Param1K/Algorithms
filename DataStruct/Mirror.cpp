// C++ program to delete element in binary tree 
#include <iostream>
#include <vector>

using namespace std; 

/* A binary tree node has key, pointer to left 
child and a pointer to right child */
typedef struct TNode { 
	int key; 
	struct TNode *left, *right; 
}TNode; 

typedef struct Node {
    TNode *curr;
    Node *next;
}Node;

typedef struct queue{
    Node *front;
    Node *rear;
}Queue;

/* function to create a new node of tree and 
return pointer */
TNode* newTNode(int key) 
{ 
	TNode* temp = new TNode; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

Node* newNode(TNode *node) 
{ 
	Node* temp = new Node; 
	temp->curr = node; 
	temp->next = NULL; 
	return temp; 
}; 

void push_back(Queue *q, TNode *root)
{
    Node *last = newNode(root);
    if(!q->front){
        q->front = q->rear = last;
    } else {
        q->rear->next =  last;
        q->rear = last;
    }
}

/* Inorder traversal of a binary tree*/
void inorder(TNode* temp) 
{ 
	if (!temp) 
		return; 
	inorder(temp->left); 
	cout << temp->key << " "; 
	inorder(temp->right); 
} 

void freeTree(TNode *root)
{
    if(root)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

void levelOrderQueue(Queue *q1, Queue *q2)
{   
    Node *node = q1->front;
    if(node && node->curr){
        if(node->curr->left){
            push_back(q2, node->curr->left);
        }
        if(node->curr->right){
            push_back(q2, node->curr->right);
        }
        cout<<node->curr->key<<" ";
        q1->front = q1->front->next;
        delete node;
        if(q1->front) {
            levelOrderQueue(q1, q2);
        } else {
            cout<<endl;
            q1->rear = NULL;
            levelOrderQueue(q2, q1);
        }
    } else {
        q1->front = q1->rear = NULL;
    }
}

void mirrorQueue(Queue *q)
{
    Node *tmp = q->front;
    if(tmp && tmp->curr)
    {
        if(tmp->curr->left)
            push_back(q, tmp->curr->left);
        if(tmp->curr->right)
            push_back(q, tmp->curr->right);

        /* SWAP left and right */
        TNode *tmp2 = tmp->curr->left;
        tmp->curr->left = tmp->curr->right;
        tmp->curr->right = tmp2;

        q->front = tmp->next;
        delete tmp;
        mirrorQueue(q);
    }
}

void  mirror3(TNode *root, TNode **newRoot)
{
    if (root)
    {
        if(!(*newRoot))
        {
            *newRoot = newTNode(root->key);
        }
        if(root->right){
            (*newRoot)->left = newTNode(root->right->key);
            mirror3(root->right, &(*newRoot)->left);
        }
        if(root->left){
            (*newRoot)->right = newTNode(root->left->key);
            mirror3(root->left, &(*newRoot)->right);
        }
    }
}

void mirror2(TNode *root, TNode **newRoot)
{
    if(root)
    {
        *newRoot = newTNode(root->key);
        mirror2(root->left, &((*newRoot)->right));
        mirror2(root->right, &((*newRoot)->left));
    }
}

// Driver code 
void mirror(TNode *root)
{
    TNode *tmp = NULL;
    if(root)
    {
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirror(root->left);
        mirror(root->right);
    }
}
// Driver code 
int main() 
{ 
	TNode* root = newTNode(10); 
	root->left = newTNode(11); 
	root->left->left = newTNode(7); 
	root->left->right = newTNode(12); 
	root->right = newTNode(9); 
	root->right->left = newTNode(15); 
	root->right->right = newTNode(8); 


    /************************Q U E U E - I M P L E M E N T A T I O N*******/
    Queue *q1 = new Queue();
    Queue *q2 = new Queue();
    q2->front = q2->rear = NULL;
    q1->front = q1->rear = NULL;
    push_back(q1, root);
	cout <<endl<< "Levelorder QUEUE Origional:"<<endl; 
    levelOrderQueue(q1, q2);

    mirror(root);
	cout<<endl<< "Mirror Based traversal :"<<endl; 
    push_back(q1, root);
    levelOrderQueue(q1, q2);

	cout<<endl<< "Mirror2 Based traversal :"<<endl; 
    q2->front = q2->rear = NULL;
    q1->front = q1->rear = NULL;
    // new tree 
    TNode *newRoot = NULL;
    mirror2(root, &newRoot);
    push_back(q1, newRoot);
    levelOrderQueue(q1, q2);
    free(newRoot);

	cout<<endl<< "Mirror3 Based traversal :"<<endl; 
    newRoot = NULL;
    mirror3(root, &newRoot);
    push_back(q1, newRoot);
    cout<<"traverse";
    levelOrderQueue(q1, q2);

	cout<<endl<< "Queue based Mirror - NO RECURSION:"<<endl; 
    push_back(q2, newRoot); 
    mirrorQueue(q2);
    push_back(q1, newRoot);
    cout<<"traverse";
    levelOrderQueue(q1, q2);
    free(newRoot);
    delete q1;
    delete q2;

    freeTree(root);
	return 0; 
} 

