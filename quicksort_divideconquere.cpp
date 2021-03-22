#include<bits/stdc++.h>
using namespace std;
int partition(int *a,int start,int last)
{
  int end = last;
  int pivot=a[end];
  end--;
  while(start<=end){
    if(a[start]>pivot)
    {
      swap(a[start],a[end]);
      end--;
    }
    else 
      start++;
  }
  swap(a[start],a[last]);
  return start;
  
}
void quicksort(int *a,int start,int end){
  if(start<end){
    int p = partition(a,start,end);
    //cout<<a[p]<<" partion point\n";
    quicksort(a,start,p-1);
    quicksort(a,p+1,end);
  }
}

int main() {

  int a[6]={1,2,3,5,8,7};
  quicksort(a,0,5);
  
  for(auto x:a)cout<<x<<" ";
  cout<<endl;

  
  
return 0; 
} 
