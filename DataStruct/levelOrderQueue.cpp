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
        free(root);
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
            vec.push_back(&(*(vec[index]->left)));
            cout<<"push back "<<vec[index]->left->key;
        }
        cout<<endl;
        if(vec[index]->right){
            vec.push_back(&(*(vec[index]->right)));
            cout<<"push back "<<vec[index]->right->key;
        }
        cout<<endl;
        levelOrder(++index, vec);
    }
}

void levelOrderQueue(Queue *q, Node *front)
{
    if(front){
        if(front->curr->left){
            push_back(q, front->curr->left);
        }
        if(front->curr->right){
            push_back(q, front->curr->right);
        }
        levelOrderQueue(q, front->next);
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

    /************************Q U E U E - I M P L E M E N T A T I O N*******/
    Queue *q = new Queue();
    q->front = q->rear = NULL;
    push_back(q, root);
    levelOrderQueue(q, q->front);

	cout <<endl<< "Levelorder QUEUE Based traversal :"<<endl; 
    for(Node* front = q->front; front;)
    {
        Node *tmp = front; 
        front = front->next;
        cout<<tmp->curr->key<<" ";
        delete tmp;
    }

    freeTree(root);
	return 0; 
} 

