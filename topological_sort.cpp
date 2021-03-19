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
    void addEdge(int s,int d){
      adj[s].push_back(d);
    }
    void dfs(stack<int>&s,vector<bool>&visited,int n){
      list<int>::iterator i;
      visited[n]=true;
      for(i=adj[n].begin();i!=adj[n].end();++i)
        if(!visited[*i])
          dfs(s,visited,*i);
      s.push(n);
     return;
    }
};
int main() {
  Graph G(8);
  G.addEdge(0,1);
  G.addEdge(0,2);
  G.addEdge(0,3);
  // G.addEdge(3,4);
  // G.addEdge(3,5);
  // G.addEdge(2,6);
  // G.addEdge(2,7);
  /*
                 0
               / | \
              /  |  \ 
             1   2    3
                / \   / \
               6   7 4   5
  */
  stack<int>s;
  vector<bool>visited(8,false);
  for(int i=0;i<8;++i){
    if(!visited[i]){
      G.dfs(s,visited,i);
      }
  }
  while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
      }
return 0; 
}
