// C++ program to delete element in binary tree 
#include <iostream>
#include <vector>
#include <map>

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

void push_front(Queue *q, TNode *root)
{
    Node *first = newNode(root);
    if(!q->front){
        q->front = q->rear = first;
    } else {
        first->next = q->front;
        q->front = first;
    }
}

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

/**************************** H E I G H T   of   T R E E********************************/
#define MAX(a,b)    ((a>b)?a:b)
int heightTree(TNode *root)
{
    if(root)
    {
        if((!root->left) && (!root->right))
            return 1;
        return(MAX(heightTree(root->left), heightTree(root->right)) + 1);
    }
    return 0;
}
/****************************W I D T H   of   T R E E******************/
int scanLeft(TNode *root, int pos)
{
    if(root)
    {
        if((!root->left) && (!root->right))
            return pos;
        int pos2 = MAX(scanLeft(root->left, pos + 1), scanLeft(root->right, pos - 1));
        return MAX(pos, pos2);
    }
}

int scanRight(TNode *root, int pos)
{
    if(root)
    {
        if((!root->left) && (!root->right))
            return pos;
        int pos2 = MAX(scanRight(root->left, pos - 1), scanRight(root->right, pos + 1));
        return MAX(pos, pos2);
    }
}

int widthTree(TNode *root)
{
    if(root)
        return(scanLeft(root->left, 1) + scanRight(root->right, 1));
    else
        return 0;
}

//-------------------------D R I V E R   C O D E ----------------------------//
int main() 
{ 
	TNode* root = newTNode(10); 
	root->left = newTNode(11); 
	root->left->left = newTNode(7); 
	root->left->right = newTNode(12); 
	root->left->right->left = newTNode(122); 
	root->left->right->left->left = newTNode(121); 
	root->left->right->left->left->left = newTNode(120); 

	root->right = newTNode(9); 
	root->right->left = newTNode(15); 
	root->right->right = newTNode(8); 
	root->right->left->right = newTNode(158); 
	root->right->left->right->right = newTNode(159); 
	root->right->left->right->right->right = newTNode(160); 

    /************************Q U E U E - I M P L E M E N T A T I O N*******/
    Queue *q1 = new Queue();
    Queue *q2 = new Queue();
    q2->front = q2->rear = NULL;
    q1->front = q1->rear = NULL;
    push_back(q1, root);
	cout <<endl<< "Levelorder QUEUE Based traversal :"<<endl; 
    levelOrderQueue(q1, q2);
    
    /**************************** H E I G H T ********************************/
    int height = heightTree(root);
    cout<<endl<<"height "<<height<<endl;

    /**************************** W I D T H***********************************/
    cout<<" WIDTH "<<widthTree(root);

    delete q1;
    delete q2;

    freeTree(root);
	return 0; 
} 
