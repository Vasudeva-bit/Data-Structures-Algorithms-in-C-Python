#include <iostream>
using namespace std;
#include <list>
class Graph
{
	int N;
	// a array of lists to store the connections in graph
	list<int> *ptr;

public:
	Graph(int N)
	{
		this->N = N;
		ptr = new list<int>[N];
	}
	void AddEdge(int a, int b)
	{
		ptr[a].push_back(b);
		ptr[b].push_back(a);
	}
	void disply()
	{
		for (int i = 0; i < N; i++)
		{
			cout << "" << i << "->";
			for (int x : ptr[i])
			{
				cout << x << ",";
			}
			cout << endl;
		}
	}
};
int main()
{
	Graph ob(5);
	ob.AddEdge(0, 1);
	ob.AddEdge(1, 2);
	ob.AddEdge(2, 3);
	ob.AddEdge(0, 2);
	ob.AddEdge(0, 4);
	ob.disply();
}
