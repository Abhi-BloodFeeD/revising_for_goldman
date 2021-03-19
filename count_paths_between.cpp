#include<bits/stdc++.h>
using namespace std;

class Graph{
  private:
    int V;
    list<int>*adj;
  public:
    Graph(int V){
      this->V=V;
      adj = new list<int>[V];
    }
    void addEdge(int fro,int to){
      adj[fro].push_back(to);
    } 
    void DFS_from_to(int u,int v,int &vis){
      
      list<int>::iterator i;
      for(i=adj[u].begin();i!=adj[u].end();++i)
      {
        if(*i==v){
          vis++;  
          return;        
        }
        DFS_from_to(*i,v,vis);
      }
      return; 
    }
    void DFS(int u,int v){
      int count=0;
      DFS_from_to(u,v,count);
      cout<<count<<endl;
      return;
    }
};
int main() {

  Graph G(11);
  G.addEdge(0,1);
  G.addEdge(0,4);
  G.addEdge(0,7);
  G.addEdge(1,2);
  //G.addEdge(1,4);
  G.addEdge(4,5);
  G.addEdge(5,6);
  G.addEdge(6,10);
  G.addEdge(2,3);
  G.addEdge(3,10);
  G.addEdge(7,8);
  G.addEdge(8,9);
  G.addEdge(9,10);
  G.DFS(0,10);
return 0; 
} 
