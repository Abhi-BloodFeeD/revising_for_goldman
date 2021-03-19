#include<bits/stdc++.h>
using namespace std;

class Graph{
  private:
    int V;
    list<int>*adj;
  
  public:
    Graph(int V)
    {
      this->V=V;
      adj = new list<int>[V];
    }
    void addEdge(int from,int to){
      adj[from].push_back(to);
    }
    void REV_NODE_BFS(int s,list<int>*rev_adj){
      vector<bool>visited(V,false);
      queue<int>q;
      q.push(s);
      list<int>::iterator i;
      while(!q.empty()){
        int p=q.front();
        q.pop();
        visited[p]=true;
        for(i=adj[p].begin();i!=adj[p].end();++i){
          if(!visited[*i]){
            q.push(*i);
            rev_adj[*i].push_back(p);
          }
          if(visited[*i]){
            rev_adj[*i].push_back(p);
          }
        }
      }
      return;
    }
};

int main() {
int V=5;
Graph g(5);
g.addEdge(0,1);
g.addEdge(0,3);
g.addEdge(0,4);
g.addEdge(2,0);
g.addEdge(3,2);
g.addEdge(4,1);
g.addEdge(4,3);
list<int>a[V];
g.REV_NODE_BFS(0,a);
for(int i =0;i<V;i++){
  auto it = a[i].begin();
  for(auto j=it;j!=a[i].end();j++){
    cout<<"FROM "<<i<<" TO "<<*j<<endl;
  }
}
return 0; 
} 
