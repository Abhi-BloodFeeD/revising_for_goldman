#include<bits/stdc++.h>
using namespace std;

class Graph{
  private:
    int V;
    vector<int> *adj;
  public:
    Graph(int V){
      this->V=V;
      adj = new vector<int>[V];
      vector<int>internal(V,0);
      for(int i=0;i<V;i++){
        adj[i] = internal;
      }
    }
    void print(){
      for(int i=0;i<V;i++)
      {
        for(int j=0;j<V;j++){
          cout<<adj[i][j]<<" ";
        }
        cout<<endl;
      }
    }
    void addEdge(int a,int b){
      adj[a][b]=1;
      adj[b][a]=1;
    }
    bool DFS(int n,int parent,vector<bool>&visited){
        visited[n]=true;
        // if(hascycle)return;
        for(int i=0;i<V;i++){
          if(adj[n][i]==1){
            if(!visited[i]){
              if(DFS(i,n,visited))
                return true;
            }
            else if(visited[i]){
              if(i!=parent)
                return true;  
            }
          }
        }
        return false;
    }
    bool detectingCycle(){
      vector<bool>visited(V,false);
      // bool hascycle=false;
      for(int i=0;i<V;i++){
        if(!visited[i])
          if(DFS(i,-1,visited))
            return true;
      }
      return false;
    }
};

int main() {
  Graph g(3);
  
  g.addEdge(0,1);
  // g.addEdge(1,2);
  g.addEdge(0,2);
  g.print();
  g.detectingCycle()? 
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
return 0; 
} 
