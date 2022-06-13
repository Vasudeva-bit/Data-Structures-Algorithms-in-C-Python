#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
	int N;
	// a array of lists to store the connections in graph
	list<int> *ptr;
	public:
		Graph(int N){
			this->N = N;
			ptr = new list<int>[N];
		}
		void addEdge(int a, int b){
			ptr[a].push_back(b);
			ptr[b].push_back(a);
		}
		void disply(){
			for(int i=0;i<N;i++){
				cout<<""<<i<<"->";
				for(int x:ptr[i]){
					cout<<x<<",";
				}
				cout<<endl;
			}
		}
		void bfs(int val){
			vector<bool> visited(N);
			list<int> que;
			que.push_back(val);
			visited[val] = true;
			while(!que.empty()){
				val = que.front();
				que.pop_front();
				for(auto i: ptr[val]){
					if(!visited[i])
					{
						// add comment
						visited[i] = true;
						cout<<"The "<<val<<" is visited and enqueued"<<endl;
						que.push_back(i);
					}
				}
			}
		}
};
int main(){
	  Graph g(6);

  // Create some edges to the vertices
  // Connections for vertex 0
  g.addEdge(0, 1);
  g.addEdge(0, 2);

  // Connections for vertex 1
  g.addEdge(1, 0);
  g.addEdge(1, 3);
  g.addEdge(1, 4);

  // Connections for vertex 2
  g.addEdge(2, 0);
  g.addEdge(2, 4);

  // Connections for vertex 3
  g.addEdge(3, 1);
  g.addEdge(3, 4);
  g.addEdge(3, 5);

  // Connections for vertex 4
  g.addEdge(4, 1);
  g.addEdge(4, 2);
  g.addEdge(4, 3);
  g.addEdge(4, 5);

  // Connections for vertex 5
  g.addEdge(5, 3);
  g.addEdge(5, 4);
  g.bfs(3);
  g.disply();
}
