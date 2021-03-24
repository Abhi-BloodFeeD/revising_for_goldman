#include<bits/stdc++.h>
using namespace std;

int mergemax(int *a,int s,int m ,int e){
  int leftmax=INT_MIN;
  int score=0;
  for(int i=m;i>=s;i--){
    score+=a[i];
    leftmax=max(leftmax,score);
  }
  int rightmax=INT_MIN;
  score=0;
  for(int i=m+1;i<=e;i++){
    score+=a[i];
    rightmax=max(rightmax,score);
  }
  return max({leftmax,rightmax,leftmax+rightmax});
}


int maxSubArraySum(int*a,int s,int e){
  if(s==e)
    return a[s];
  int m = (s+e)/2;
  return max({maxSubArraySum(a,s,m),
  maxSubArraySum(a,m+1,e),
  mergemax(a,s,m,e)});
}

int main() {

int arr[] = { 2, 3, 4, 5, 7 };
int n=5;
int mx= maxSubArraySum(arr,0,n-1);
cout<<mx<<endl;  
return 0; 
} 
