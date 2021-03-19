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
    void BFS(int from,int to){
      vector<bool>visited(V,false);
      queue<int>q;
      q.push(from);
      while(!q.empty()){
        int p=q.front();
        q.pop();
        visited[p]=true;
        list<int>::iterator it;
        for(it = adj[p].begin();it !=adj[p].end();++it){
          if(!visited[*it]){
            q.push(*it);
          }
        }
      }
    }
};

int main() {
  int m,n,k,r;
  int X[k];int Y[k];
  Graph g(m*n);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      
    }
  }


  
  
return 0; 
} 
