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

/*void levelOrder(vector<TNode *>::iterator it, vector<TNode *> vec){
    if(*it != NULL)
    {
        if((*it)->left){
            vec.push_back((*it)->left);
            cout<<"push back "<<(*it)->left->key;
        }
        if((*it)->right){
            vec.push_back((*it)->right);
            cout<<"push back "<<(*it)->left->key;
        }
    }
    levelOrder(++it, vec);
}*/
void levelOrder(int index, vector<TNode *>& vec)
{
    if((index < vec.size()) &&vec[index])
    {
        if(vec[index]->left){
            vec.push_back(vec[index]->left);
        }
        if(vec[index]->right){
            vec.push_back(vec[index]->right);
        }
        levelOrder(++index, vec);
    }
}
void spiralTraverse(Queue *q1, Queue *q2, int lvl)
{
    Node *front = q1->front;
    if(front && front->curr)
    {
        cout<<front->curr->key<<" ";
        if(front->curr->left)
        {
            if(lvl)
                push_front(q2, front->curr->left);
            else
                push_back(q2, front->curr->left);
        }
        if(front->curr->right)
        {
            if(lvl)
                push_front(q2, front->curr->right);
            else
                push_back(q2, front->curr->right);
        }
        q1->front = q1->front->next;
        delete front;
        if(q1->front){
            spiralTraverse(q1, q2, lvl);
        }else{
            cout<<endl; 
            spiralTraverse(q2, q1, !lvl);
        }
    } else {
        q1->front = q1->rear = NULL;
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

/**************************** T O P    V I E W********************************/
void topRight(TNode *root, int bflag)
{
    if(root)
    {
        if(bflag) 
            cout<<root->key<<" ";
        if(root->right)topRight(root->right, 1);
        /* Leaf node */
    }

}
void topLeft(TNode *root, int bflag)
{
    if(root)
    {
        if(root->left)topLeft(root->left, 1);
        if(bflag)cout<<root->key<<" ";
    }

}
void topView(TNode *root)
{
    if(root)
    {
        topLeft(root->left, 1);
        cout<<root->key<<" ";
        topRight(root->right, 1);
    }
}
//---------------------------BOUNDARY SCAN--------------------
void scanRight(TNode *root, int bflag)
{
    if(root)
    {
        if(root->left)scanRight(root->left, 0);
        if(root->right)scanRight(root->right, 1);
        /* Leaf node */
        if(bflag || (!(root->left || root->right)))
            cout<<root->key<<" ";
    }

}
void scanLeft(TNode *root, int bflag)
{
    if(root)
    {
        if(bflag)cout<<root->key<<" ";
        if(root->left)scanLeft(root->left, 1);
        if(root->right)scanLeft(root->right, 0);
        /* Leaf node */
        if(!bflag && !(root->left || root->right))
            cout<<root->key<<" ";
    }

}
void boundaryScan(TNode *root)
{
    if(root)
    {
        cout<<root->key<<" ";
        scanLeft(root->left, 1);
        scanRight(root->right, 1);
    }
}
//---------------------------------------------------------
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

	cout << "Inorder traversal before deletion : "; 
	inorder(root); 

	cout << endl; 

    /************************V E C T O R - I M P L E M E N T A T I O N*******/
    vector<TNode*> vec;
    vec.push_back(root);

    levelOrder(0, vec);

	cout << "Levelorder Vector Based traversal :"<<endl; 

    vector<TNode*>::iterator it; 
    for(it = vec.begin();it != vec.end();it++)
        cout<<(*it)->key<<" ";

    cout<<flush;
    /************************Q U E U E - I M P L E M E N T A T I O N*******/
    Queue *q1 = new Queue();
    Queue *q2 = new Queue();
    q2->front = q2->rear = NULL;
    q1->front = q1->rear = NULL;
    push_back(q1, root);
	cout <<endl<< "Levelorder QUEUE Based traversal :"<<endl; 
    levelOrderQueue(q1, q2);
    
    /**********************Spiral Traversal********************/
    push_back(q1, root);
	cout <<endl<< "SPIRAL Levelorder QUEUE Based traversal :"<<endl; 
    spiralTraverse(q1, q2, 0);
    
    cout<<endl<<"boundary scan"<<endl;
    boundaryScan(root);

    /**************************** T O P    V I E W********************************/
	cout <<endl<< "Top View :"<<endl; 
    topView(root);

    delete q1;
    delete q2;

    freeTree(root);
	return 0; 
} 

