#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>&nums1, vector<int>&nums2) {
    if(nums1.size()>nums2.size()) 
      return findMedianSortedArrays(nums2,nums1);
    
    int X=nums1.size();
    int Y=nums2.size();
    int start=0;
    int end=X;
    while(start<=end){
        
      int partitionX = (start+end)/2;
      int partitionY = (X+Y+1)/2 - partitionX;

      int maxLeftX = (partitionX==0)?INT_MIN:nums1[partitionX-1];
      int minRightX = (partitionX==X)?INT_MAX:nums1[partitionX];

      int maxLeftY = (partitionY==0)?INT_MIN:nums2[partitionY-1];
      int minRightY = (partitionY==Y)?INT_MAX:nums2[partitionY];

      if(maxLeftY<=minRightX && maxLeftX<=minRightY){
        if((X+Y)%2==0)
          return (double)(min(minRightX,minRightY)+max(maxLeftX,maxLeftY))/2;
        else
          return (double)max(maxLeftX,maxLeftY);
      }
      else if(maxLeftX>minRightY){
        end = partitionX-1;
      }
      else{
        start = partitionX+1;
      }
    }
}

int main() {
  vector<int>nums1 = {1,2,2,5};
  vector<int>nums2 = {1,7,8,9};
  cout<<findMedianSortedArrays(nums1,nums2);
return 0; 
} 
