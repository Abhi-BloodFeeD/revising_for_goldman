#include<bits/stdc++.h>
using namespace std;

class Graph{
  private:
    int V;
    list<int>*adj;
  public:
    Graph(int V){
      this->V = V;
      adj = new list<int>[V];
    }
    void addEdge(int i,int j){
      adj[i].push_back(j);
      adj[j].push_back(i);
    }

    int BFS(int n1,int n2){

      int visited[V];
      memset(visited,0,sizeof(visited));
      queue<int>q;
      visited[n1]=1;
      q.push(n1);
      list<int>::iterator i;
      while(!q.empty()){
          int p = q.front();
          q.pop();
          for(i=adj[p].begin();i!=adj[p].end();i++)
          {
            if(!visited[*i]){
              visited[*i]=visited[p]+1;
              q.push(*i);
            }
            if(*i==n2)
              return visited[*i]-1;
          }    
      }
    }
};

// find all numbers sieve method
void sieve(vector<int>&v){
  int n=9999;
  bool prime[n+1];
  memset(prime,true,sizeof(prime));
  for(int i=2;i*i<=n;i++)
    if(prime[i]==true){
      for(int p=i*i;p<=n;p+=i){
        prime[p]=false; 
      }
    }

  for(int i=1000;i<=n;i++){
    if(prime[i])
      v.push_back(i);
  }
}

bool comparator(int n1,int n2){
  string s1,s2;
  s1 = to_string(n1);
  s2 = to_string(n2);
  int c=0;
  if(s1[0]!=s2[0])
  c++;
  if(s1[1]!=s2[1])
  c++;
  if(s1[2]!=s2[2])
  c++;
  if(s1[3]!=s2[3])
  c++;
  return c==1;
}
// function comppare that compares if two numbers differ by 1 digit;
// add edges all those numbers which differ only by 1 digit
//
void shortestpath(int n1,int n2){
  
  vector<int>v;
  sieve(v);
  Graph g(v.size());
  for(int i=0;i<v.size();i++)
    for(int j=i+1;j<v.size();j++){
      if(comparator(v[i],v[j]))
        g.addEdge(i,j);
    }

  int no1,no2;
  for(int i=0;i<v.size();i++){
    if(v[i]==n1)
      no1=i;}
  for(int i=0;i<v.size();i++){
    if(v[i]==n2)
      no2=i;
  }
  cout<<g.BFS(no1,no2)<<endl;
  

}

int main() 
{ 
    int num1 = 1033, num2 = 8179; 
    shortestpath(num1, num2); 
    return 0; 
} 