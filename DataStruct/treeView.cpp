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

/**************************** T O P    V I E W********************************/
void topRight(TNode *root, map<int, TNode *> &mp, int pos, int bflag)
{
    if(root)
    {
        if(bflag)
        {
            auto it = mp.find(pos);
            if(it == mp.end())
                mp[pos] = root;
        }
        if(root->right)topRight(root->right, mp, pos + 1, 1);
        if(root->left)topRight(root->left, mp, pos - 1, 0);
    }

}
void topLeft(TNode *root, map<int, TNode *> &mp, int pos, int bflag)
{
    if(root)
    {
        if(bflag)
        {
            auto it = mp.find(pos);
            if(it == mp.end())
                mp[pos] = root;
                //mp.at(pos) = root;
                //(*it).second = root;
        }
        if(root->left)topLeft(root->left, mp, pos - 1, 1);
        if(root->right)topLeft(root->right, mp, pos + 1, 0);
    }
}
void topView(TNode *root)
{
    map<int, TNode *> mp;
    if(root)
    {
        topLeft(root->left, mp, -1, 1);
        mp[0] = root;
        topRight(root->right, mp, 1, 1);
    }
    auto itr = mp.begin();
    while(itr != mp.end())
    {
        cout<<itr->second->key<<" ";
        itr++;
    }
    mp.clear();
    //while(!mp.empty())mp.erase(mp.begin());
    //auto it = mp.begin();while(it != mp.end())mp.erase(it);
}

/**************************** B O T T O M    V I E W ********************************/
void bottomRight(TNode *root, map<int, TNode *> &mp, int pos)
{
    if(root)
    {
        auto it = mp.find(pos);
        if(it == mp.end())
            mp[pos] = root;
        else
            (*it).second = root;
        
        if(root->right)bottomRight(root->right, mp, pos + 1);
        if(root->left)bottomRight(root->left, mp, pos - 1);
    }

}

void bottomLeft(TNode *root, map<int, TNode *> &mp, int pos)
{
    if(root)
    {
        auto it = mp.find(pos);
        if(it == mp.end())
            mp[pos] = root;
        else
            (*it).second = root;

        if(root->left)bottomLeft(root->left, mp, pos - 1);
        if(root->right)bottomLeft(root->right, mp, pos + 1);
    }
}
void bottomView(TNode *root)
{
    map<int, TNode *> mp;
    if(root)
    {
        bottomLeft(root->left, mp, -1);
        mp[0] = root;
        bottomRight(root->right, mp, 1);
    }
    auto itr = mp.begin();
    while(itr != mp.end())
    {
        cout<<itr->second->key<<" ";
        itr++;
    }
    mp.clear();
    //while(!mp.empty())mp.erase(mp.begin());
    //auto it = mp.begin();while(it != mp.end())mp.erase(it);
}

/****************************L E F T    V I E W ********************************/
void leftLeft(TNode *root, map<int, TNode *> &mp, int height)
{
    if(root)
    {
        auto it = mp.find(height);
        if(it == mp.end())
            mp[height] = root;

        if(root->left)leftLeft(root->left, mp, height + 1);
        if(root->right)leftLeft(root->right, mp, height + 1);
    }
}

void leftView(TNode *root)
{
    map<int, TNode *> mp;
    if(root)
    {
        mp[0] = root;
        leftLeft(root->left, mp, 1);
        leftLeft(root->right, mp, 1);
    }
    auto itr = mp.begin();
    while(itr != mp.end())
    {
        cout<<itr->second->key<<" ";
        itr++;
    }
    mp.clear();
    //while(!mp.empty())mp.erase(mp.begin());
    //auto it = mp.begin();while(it != mp.end())mp.erase(it);
}

/****************************R I G H T    V I E W ********************************/
void rightRight(TNode *root, map<int, TNode *> &mp, int height)
{
    if(root)
    {
        auto it = mp.find(height);
        if(it == mp.end())
            mp[height] = root;

        if(root->right)rightRight(root->right, mp, height + 1);
        if(root->left)rightRight(root->left, mp, height + 1);
    }
}

void rightView(TNode *root)
{
    map<int, TNode *> mp;
    if(root)
    {
        mp[0] = root;
        rightRight(root->right, mp, 1);
        rightRight(root->left, mp, 1);
    }
    auto itr = mp.begin();
    while(itr != mp.end())
    {
        cout<<itr->second->key<<" ";
        itr++;
    }
    mp.clear();
}


//-------------------------D R I V E R   C O D E ----------------------------//
int main() 
{ 
	TNode* root = newTNode(10); 
	root->left = newTNode(11); 
	root->left->left = newTNode(7); 
	root->left->right = newTNode(12); 
	root->right = newTNode(9); 
	root->right->left = newTNode(15); 
	root->right->right = newTNode(8); 
	root->left->right->left = newTNode(122); 
	root->left->right->left->left = newTNode(121); 
	root->left->right->left->left->left = newTNode(120); 
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
    
    /**************************** T O P    V I E W********************************/
	cout <<endl<< "Top View :"<<endl; 
    topView(root);

    /**************************** B O T T O M    V I E W********************************/
    cout<<endl<<"BOTTOM VIEW"<<endl;
    bottomView(root);

    /**************************** L E F T    V I E W********************************/
    cout<<endl<<"LEFT VIEW"<<endl;
    leftView(root);

    /**************************** R I G H T    V I E W********************************/
    cout<<endl<<"RIGHT VIEW"<<endl;
    rightView(root);

    delete q1;
    delete q2;

    freeTree(root);
	return 0; 
} 
