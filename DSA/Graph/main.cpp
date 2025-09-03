#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
  int a[5][5]{0};
  vector<int> elems;

 public:
  void rm_dup() {
    sort(elems.begin(), elems.end());
    elems.erase(unique(elems.begin(), elems.end()), elems.end());
  }

  void Insert(int x, int y) {
    if ((x > 4 || x < 0) || (y > 4 || y < 0)) return;
    a[x][y] = 1;
    a[y][x] = 1;
    elems.push_back(x);
    elems.push_back(y);
    rm_dup();
  }
  void display() {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl << endl;
  }

  void BFS() {
    if (elems.empty()) return;

    bool visited[5]{false};
    queue<int> qi;
    qi.push(elems[0]);
    visited[elems[0]] = true;

    while (!qi.empty()) {
      int node = qi.front();
      cout << node << " ";
      qi.pop();

      for (int i = 0; i < 5; i++) {
        if (a[node][i] == 1 && !visited[i]) {
          qi.push(i);
          visited[i] = true;
        }
      }
    }
  }
  void DFS(vector<bool> &vis, int node = 0) {
    cout << node << " ";
    vis[node] = true;

    for (int j = 0; j < 5; j++) {
      if (a[node][j] == 1 && !vis[j]) {
        DFS(vis, j);
      }
    }
  }
};

int main(int argc, char **argv) {
  Graph g1;
  vector<bool> vi(5, false);
  g1.Insert(0, 1);
  g1.Insert(0, 2);
  g1.Insert(1, 3);
  g1.Insert(2, 3);
  g1.display();
  cout<<"BFS: "; g1.BFS(); cout<<endl;
  cout<<"DFS: ";g1.DFS(vi);
  return 0;
}
