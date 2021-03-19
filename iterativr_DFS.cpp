#include<bits/stdc++.h>
using namespace std;

class Graph{
  private:
    int V;
    list<int>*adj;
    void DFSutil(int n);
  public:
    Graph(int V){
      this->V = V;
      adj = new list<int>[V];
    }
    void DFS_iterative(int n){
      stack<int>st;
      vector<bool> visited(V,false);
      st.push(n);
      while(!st.empty()){
        int x = st.top();
        st.pop();
        if(!visited[x]){
          visited[x]=true;
          cout<<"visited From "<<x<<endl;
        }
        list<int>::iterator i;
        for(i=adj[x].begin();i!=adj[x].end();++i)
          if(!visited[*i])
            st.push(*i);
      }
    }
    void addEdges(int from,int to){
      adj[from].push_back(to);
    }
};

int main() {
  Graph G(9);
  G.addEdges(0,1);
  G.addEdges(1,2);
  G.addEdges(2,3);
  G.addEdges(0,4);
  G.addEdges(4,5);
  G.addEdges(5,6);
  G.addEdges(6,7);
  G.addEdges(7,8);
  G.DFS_iterative(0);
  
return 0; 
} 
