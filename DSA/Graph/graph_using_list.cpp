#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
		vector<vector<int>> adlist;
		vector<bool> visited;
public:
		Graph(int v){ adlist.resize(v); }
		void Insert(int x, int y){
				adlist[x].push_back(y);
				adlist[y].push_back(x);
				visited.resize(adlist.size(),false);
		}
		void display(){
				for(size_t i=0;i<adlist.size();i++){
					cout<<i<<" - [";
					for(size_t j=0;j<adlist[i].size();j++)
						cout<<adlist[i][j]<<",";
					cout<<"]\n";
				}		
				cout<<endl;
		}
		void clrVisited(){
			visited.resize(adlist.size(), false);
		}
		void BFS(){
			vector<bool> visited(adlist.size(),false);
			queue<int> qi;
			qi.push(0);
			visited[0] = true;
			while(!qi.empty()){
					int node = qi.front();
					cout<<node<<" ";
					for(size_t i=0;i<adlist[node].size();i++)
						if( !visited[adlist[node][i]])
						{	qi.push(adlist[node][i]); visited[adlist[node][i]] = true; }
					qi.pop();
			}
			clrVisited();
		}
		void DFS(int node=0){
			cout<<node<<" ";
			visited[node] = true;
			for(size_t i=0;i<adlist[node].size();i++){
				if(!visited[adlist[node][i]])
					DFS(adlist[node][i]);
			}
			clrVisited();
		}
};

int main(int argc, char **argv)
{
	Graph g1(10);

	g1.Insert(0,1);
	g1.Insert(2,3);
	g1.Insert(4,2);
	g1.Insert(2,6);
	g1.Insert(3,8);
	g1.Insert(4,3);
	g1.Insert(1,3);
	g1.display();
	cout<<"BFS: ";g1.BFS(); cout<<endl;
	cout<<"DFS: ";g1.DFS(); cout<<endl;
	return 0;
}

