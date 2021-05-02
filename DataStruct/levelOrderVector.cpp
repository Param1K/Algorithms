// C++ program to delete element in binary tree 
#include <iostream>
#include <vector>

using namespace std; 

/* A binary tree node has key, pointer to left 
child and a pointer to right child */
struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

/* function to create a new node of tree and 
return pointer */
struct Node* newNode(int key) 
{ 
	struct Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp) 
{ 
	if (!temp) 
		return; 
	inorder(temp->left); 
	cout << temp->key << " "; 
	inorder(temp->right); 
} 

void freeTree(Node *root)
{
    if(root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/*void levelOrder(vector<Node *>::iterator it, vector<Node *> vec){
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
void levelOrder(int index, vector<Node *>& vec)
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

// Driver code 
int main() 
{ 
	struct Node* root = newNode(10); 
	root->left = newNode(11); 
	root->left->left = newNode(7); 
	root->left->right = newNode(12); 
	root->right = newNode(9); 
	root->right->left = newNode(15); 
	root->right->right = newNode(8); 

	cout << "Inorder traversal before deletion : "; 
	inorder(root); 

	cout << endl; 

    vector<Node*> vec;
    vec.push_back(root);

    levelOrder(0, vec);

	cout << "Levelorder traversal :"<<endl; 

    vector<Node*>::iterator it; 
    for(it = vec.begin();it != vec.end();it++)
        cout<<(*it)->key<<" ";

    freeTree(root);
	return 0; 
} 

