#include<bits/stdc++.h>
using namespace std;


int main() {
  int parent[5]={-1, 0, 1, 2, 3};
  int max_score=0;
  for(int i=0;i<5;i++){
    int k = i;
    int score=0;
    while(parent[k]!=-1){
      k=parent[k];
      score++;
    }
    max_score=max(score,max_score);
  }
  cout<<max_score<<endl;
  
  
  
return 0; 
} 
