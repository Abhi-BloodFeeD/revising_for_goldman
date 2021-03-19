#include<bits/stdc++.h>
using namespace std;

class graph{
  private:
    int V;
    list<int> *adj;
  public:
    graph(int V){
      this->V=V;
      adj = new list<int>[V];
    } 
    void addEdge(int n,int m){
      adj[n].push_back(m);
      adj[m].push_back(n);
    }
    int BFS(int s,vector<int>&visited){
      queue<int>q;
      q.push(s);
      while(!q.empty()){
        int p=q.front();
        visited[p]=true;
        q.pop();
        list<int>::iterator i;
        for(i=adj[p].begin();i!=adj[p].end();++i){
          if(!visited[*i]){
            q.push(*i); 
          }
        }
      }
    }
    int BFS_Caller(int V){
      vector<int>visited(V,false);
      int count=0;
      for(int i=0;i<V;i++){
        if(!visited[i])
        {
          BFS(i,visited);
          count++;
        } 
      
      }
      return count;
    }
};

int main() {
    int V = 12; 
    graph G(V); 
    G.addEdge( 0, 1); 
    G.addEdge( 2, 3); 
    G.addEdge( 4, 5); 
    G.addEdge( 6, 7); 
    G.addEdge( 7, 8); 
    G.addEdge( 9, 10);
    G.addEdge(10,11); 
    cout << G.BFS_Caller(V); 
    return 0; 

  
  
return 0; 
} 
