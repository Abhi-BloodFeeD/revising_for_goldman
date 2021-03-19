#include<bits/stdc++.h>
using namespace std;

void primes(int n){
  bool prime[n+1];
  memset(prime,true,sizeof(prime));
  vector<int>sol;
  for(int i=2;i*i<=n;i++){
    if(prime[i]==true){
      for(int z=i*i;z<=n;z+=i){
        prime[z]=false;
      }
    }
  }
  for(int i=2;i<=n;i++){
    if(prime[i])cout<<i<<" ";
  }

  return ;
}


int main() {
  primes(100);
  
  return 0; 
} 
