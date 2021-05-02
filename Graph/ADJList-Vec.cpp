#include<iostream>
#include<vector>
using namespace std;

// Graph can be represented in std::vector, std::set, std::list.
class Graph{
	private:
		int v;
		vector<int>adjList;
	public:
	Graph(){}
	//Graph(int sz): v(sz), adjList(vector<int>(sz)) {}
	void addEdge( int d) {
		adjList.push_back(d);
	}
	~Graph(){}
};

int main()
{
	Graph g[10];
	g[0].addEdge(1);
	g[0].addEdge(2);
	g[1].addEdge(3);
	
}