#include<bits/stdc++.h>
using namespace std;


class Graph{
  private:
    int V;
    list<int>*adj;//poiter to array of lists;
    //void DFSutil(int v,vector<bool>&visited);
  public:
    Graph(int V){
      this->V=V;
      adj = new list<int>[V];//array of lists;
    }
    void addEdge(int fm,int to){
      adj[fm].push_back(to);
    }
    void DFSutil(int v,vector<bool>&visited){   
      list<int>::iterator i;
      visited[v]=true;
      cout<<v<<endl;
      for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
          DFSutil(*i,visited);
        }
      }
    }
    void DFS(){
      vector<bool> visited(V,false);
      for(int i=0;i<V;i++){
        if(!visited[i]){
          cout<<"TRAVERSING "<<i<<endl;
          DFSutil(i,visited);
        }
      }
    }
    
};


int main()
{
    // Create a graph given in the above diagram
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    //g.addEdge(1, 2);
    //g.addEdge(2, 0);
    //g.addEdge(2, 3);
    //g.addEdge(3, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    cout << "Following is Depth First Traversal \n";
    g.DFS();
    return 0;
}
