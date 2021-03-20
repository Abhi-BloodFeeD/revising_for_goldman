#include<bits/stdc++.h>
using namespace std;

class graph{
  private:
    int V;
    list<int>*adj;
  public:
    graph(int n){
      this->V=n;
      adj = new list<int>[V];
    }
    void addEdge(int fr,int to){
      adj[fr].push_back(to);
      // adj[to].push_back(to);
      
    }
    bool coloring(int n,vector<int>visited){
      if(visited[n]==2)
        return true;
      
      visited[n]=1;
      list<int>::iterator i;
        for(i=adj[n].begin();i!=adj[n].end();++i){
          if(visited[*i]==1)
            visited[*i]==2;
          else{
            if(coloring(*i,visited))  
              return true;
          }
        }
      return false;      
    }

};


int main() {

int v =3;
graph g(v);
g.addEdge(0,1);
g.addEdge(1,2);
// g.addEdge(0,2);
vector<int>visited(v,0);
bool alredycontain=false;
for(int i=0;i<v;i++){
  if(visited[i]==0 &&!alredycontain)
    if(g.coloring(i,visited)){
      cout<<"TRUE \n";
      alredycontain=true;
    }
    
}if(!alredycontain)cout<<"NO LOOP\n";
return 0; 
} 
