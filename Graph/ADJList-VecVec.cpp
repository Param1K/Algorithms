#include<iostream>
#include<vector>
using namespace std;

// Graph can be represented in std::vector, std::set, std::list.
class Graph{
	private:
		int v;
		vector<vector<int>>adjList;
	public:
	Graph(){}
	Graph(int sz) {adjList.reserve(sz);}
	void addEdge( int s, int d) {
		adjList[s].push_back(d);
	}
	~Graph(){}
};

int main()
{
	Graph g(10);
	g.addEdge(9, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	
}