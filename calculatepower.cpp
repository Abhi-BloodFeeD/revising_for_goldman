#include<bits/stdc++.h>
using namespace std;



long long power(int x,int n ){
  if(n==1)return x;
  return power(x,n/2)*power(x,ceil((float)n/2));
}
int main() {
  cout<<power(15,3);
return 0; 
} 
