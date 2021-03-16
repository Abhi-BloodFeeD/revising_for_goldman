#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mod = 1e9+7;
const int mxN = 1e6;
const int N = 2e5;

struct Node{
  int data;
  vector<int> next;
};

class Graph{
  private:
    int Nodes;
    vector<vector<int>> points;

  public:
    Graph(int N){Nodes=N;}
    Graph(int N , vector<vector<int>> &T){
      Nodes=N;
      points = T;
    }
    Graph(int N,vector<vector<int>>&&T){
      Nodes = N;
      points = move(T);
    }
    
    bool path(int a,int b){
      auto it = find(points[a].begin(),points[a].end(),b);
      return(!(it==points[a].end()));   
    }

    int size(){
      return Nodes;
    }

    vector<int> size_in(int dd){
      return points[dd];
    }
    
    void BFS(int begin){
      queue<int> q;
      int k= size();
      bool visited[k+1]={false}; 
      visited[begin]=true;
      q.push(begin);
      while(!q.empty()){
        int curr = q.front();
        cout<<curr<<endl;
        q.pop();
        vector<int> to=size_in(curr);
        for(auto x: to){
            if(!visited[x])
              visited[x]=true;  
              q.push(x);
        }
      }
      return;
   }
};


int main() {
  
  vector<vector<int>>v={{1,2,7},{0},{0,3},{4},{5},{6},{0}};
  auto G = Graph(8,v);
  cout<< G.size() <<" SIZE"<<endl;
  if(G.path(0,1))cout<<"PATH 0-1\n";
  if(!G.path(3,5))cout<<"NO patH 3-5\n";;
  G.BFS(0);

return 0; 
} 
