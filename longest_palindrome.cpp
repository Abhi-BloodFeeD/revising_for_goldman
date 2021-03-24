#include<bits/stdc++.h>
using namespace std;





int main() {

string s;
cin>>s;
int N=s.size();
bool ab[N][N]={false};
memset(ab,false,sizeof(ab));
for(int i=0;i<N;i++)
  for(int j=i;j<N;j++){
    if(i==j) ab[i][j]==true;
    if(j==i+1 && s[i]==s[j]) ab[i][j]=true; 
}
for(int i=0;i<N;i++)
  for(int j=i;j<N;j++){
    if(i+1<N && j-1 > -1 && ab[i+1][j-1]==true 
                && s[i]==s[j])
                ab[i][j]=true;    
  }


return 0; 
} 
