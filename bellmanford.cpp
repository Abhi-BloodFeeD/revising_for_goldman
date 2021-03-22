#include<bits/stdc++.h>
using namespace std;

class graph{
  private:
    int V;
    list<pair<int,int>> * adj;
  public:
    graph(int V){
      this->V=V;
      adj=new list<pair<int,int>>[V];
    }
    void addedge(int a,int b,int weight){
      adj[a].push_back(make_pair(b,weight));
    }
    void BellmanFordUtil(int p,vector<int>&distance,vector<bool>visited){
      list<pair<int,int>>::iterator i;
      visited[p]=true; 
       {
        for(i=adj[p].begin();i!=adj[p].end();++i){
          distance[(*i).first]=min(distance[(*i).first],distance[p]+(*i).second);
          if(!visited[(*i).first]){
            BellmanFordUtil((*i).first,distance,visited);        
          }
        }


      }

    }

    bool BellmanFord(){
      vector<int>distance(V,INT_MAX);
      distance[0]=0;
      vector<bool>visited(V,false);
      for(int i=0;i<V-1;i++){
        vector<int>follow = distance;
        BellmanFordUtil(0,distance,visited);
        if(follow==distance)
          return false;
      }
      return true;
    }
};

int main() {
  graph G(4);
  G.addedge(0,1,1);
  G.addedge(1,2,-1);
  G.addedge(2,3,-1);
  G.addedge(3,0,1);
  G.BellmanFord()?cout<<"HAS -ve\n":cout<<"NO Negative\n";
  
  
return 0; 
} 
