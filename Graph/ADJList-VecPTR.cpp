#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Graph can be represented in std::vector, std::set, std::list.
class Graph{
	private:
		int v;
		vector<int> *adjList;
	public:
	Graph(){}
	Graph(int sz): v(sz), adjList(new vector<int>[sz]) {}
	void addEdge( int s, int d) 
	{
		if((s < v) & (d < v))
			adjList[s].push_back(d);
	}
	
	void DFSRec(int i, int *arr){
		if(!arr[i]) {
			arr[i] = 1;
			cout<<i<<"   ";

			for(auto vert : this->adjList[i]){
				//arr[vert] = 1;
				DFSRec(vert, arr);
			}
		}
	}

	void DFS(int start)
	{	
		int *visited = new int[v] {0};//[v] = {0};

		DFSRec(start, visited);
	}
	
	void BFS(int start){
		queue<int> q;
		int *visited = new int[v] {0};
		q.push(start);
		int curr = q.front();
		//while((curr = q.front()) && !visited[curr])
		while(!q.empty())
		{
			q.pop();
			if(!visited[curr]) {
				visited[curr] = 1;
				cout<<curr<<"  ";
				for(auto x: this->adjList[curr]){
					if(!visited[x]) {
						q.push(x);
						//cout<<x;
					}
				}
			}
			curr = q.front();
		}
	}
	~Graph(){}
};

int main()
{
	Graph g(10);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 1);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(4, 3);
		g.addEdge(0, 5);


	cout<<'\n'<<"DFS"<<'\n';
	g.DFS(0);
	cout<<'\n'<<"BFS"<<'\n';
	g.BFS(0);

	
}




