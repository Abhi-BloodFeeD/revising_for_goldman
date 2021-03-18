#include<bits/stdc++.h>
using namespace std;

class Graph{
  private:
    int V;
    list<int> *adj;
    void DFSutil(int v,vector<bool> &visited);
  public: 
    Graph(int v);
    void addEdge(int from,int to);
    int findMother();
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}
void Graph::DFSutil(int v,vector<bool>&visited)
{
  visited[v]=true;
  list<int>::iterator it;
  for(it=adj[v].begin();it!=adj[v].end();it++)
  {
    if(!visited[*it]){
        // visited[*it]=true;
        DFSutil(*it,visited);
    }
  }
}
void Graph::addEdge(int v,int w)
{
  adj[v].push_back(w);
}
int Graph::findMother()
{
  vector<bool>visited(V,false);
  int v=0;
  //int V = this->V;
  for(int i=0;i<this->V;i++){
    if(!visited[i]){
      DFSutil(i,visited);
      v=i;
    }
  }
  fill(visited.begin(),visited.end(),false);
  DFSutil(v,visited);
  for(int i=0;i<V;i++){
    if(!visited[i])
      return -1;
  }
  return v;
}




int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
 
    cout << "A mother vertex is " << g.findMother();
 
    return 0;
} 
