#include<bits/stdc++.h>
using namespace std;


void merge(int *a,int s1,int s2,int end){
  int l=s2-s1;int r=end-s2+1;
  int L[l];int R[r];
  for(int i=0;i<l;i++){
    L[i]=a[s1+i];
  }
  for(int i=0;i<r;i++){
    R[i]=a[s2+i];
  }

  int i=s1,run1=0,run2=0;
  while(run1<l && run2<r){
    if(L[run1]<=R[run2]){
      a[i]=L[run1];
      i++;run1++;
    }
    if(L[run1]>R[run2]){
      a[i]=R[run2];
      i++;run2++;
    }
  }
  while(run1<l){
    a[i]=L[run1];
    run1++;i++;
  }
  
  while(run2<r){
    a[i]=R[run2];
    run2++;i++;
  }
  return;
}

void mergeSort(int *a,int start,int end)
{
    if(start == end) return;
    int mid = start+((end-start)/2);
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a,start,mid+1,end);
    return;
}

int main() {
int a[6]={1,8,7,2,3,4};
mergeSort(a,0,5);  
for(auto x:a)cout<<x<<" ";
return 0; 
} 
