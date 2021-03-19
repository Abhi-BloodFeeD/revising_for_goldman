#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int source,list<int>*graph,int V){
  // vector<int>visited(V,fals);
  // int V=sizeof(graph)/sizeof(graph[0]);
  bool visited[V];
  vector<int> level(V,0);
  memset(visited,false,sizeof(visited));
  queue<int>q;
  q.push(source);  
  level[source]=0;
  list<int>::iterator i;
  while(!q.empty()){
    int p = q.front();
    q.pop();
    visited[p]=true;
    for(i=graph[p].begin();i!=graph[p].end();++i){  
      if(!visited[*i]){
        q.push(*i);
        level[*i]=level[p]+1;
      }
    }    
  }
  return level;
}


int main() { 
  int V = 8; 
    list<int> graph[V]; 
    graph[0].push_back(1); 
    graph[0].push_back(2); 
    graph[1].push_back(3); 
    graph[1].push_back(4); 
    graph[1].push_back(5); 
    graph[2].push_back(5); 
    graph[2].push_back(6); 
    graph[6].push_back(7); 
    vector<int> a = BFS(0,graph,8);
    // int n = sizeof(a)/sizeof(a[0]);
    // cout<<n<<" SIZE"<<endl;
    for(int i=0;i<V;i++)
      cout<<" Level Node "<<i<<" is "<<a[i]<<endl;
 
  
  
return 0; 
} 
