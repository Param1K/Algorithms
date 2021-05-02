#include<iostream>


/**************************************
int **ptr;    
    int *val;    
    int x = 7;    
    val = &x;    
    ptr = (int**)malloc(sizeof(int**));    
    *ptr = (int *)malloc(10 * sizeof (*val));    
    *ptr[0] = *val;    
    printf("%d\n", *ptr[0] );    
******************************************/



typedef struct Vertex{
	int node;
	int weight;
	Vertex *dest;
}Vertex;

void insertEdge(Vertex *g[], int s, int d)
{	Vertex *root = g[s];
	Vertex *temp = (Vertex *) malloc(sizeof(Vertex));
	temp->node = d;
	temp->dest = NULL;
	
	if(!root) {
		g[s] = temp;
	}else{
		while(root && root->dest)
			root=root->dest;
		root->dest = temp;
	}
	
}
void cleanup(Vertex *g[], int sz){
	for(int i = 0; i < sz; i++)
	{
		Vertex *tmp = g[i];
		while(tmp)
		{
			std::cout<<i<<".  ->  "<<tmp->node<<'\n';
			Vertex *next = tmp->dest;
			free(tmp);
			tmp = next;	
		}	
	}
	//free(g);
}
int main(){
	Vertex *g[10];
	std::memset(g,0,sizeof(Vertex *) * 10);
	insertEdge(g, 1, 2);
	insertEdge(g, 2,3);
	cleanup(g, 10);
}

