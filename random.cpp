// A C++ program for Prim's Minimum  
// Spanning Tree (MST) algorithm. The program is  
// for adjacency matrix representation of the graph  
#include <bits/stdc++.h> 
using namespace std; 
  
    double findMedianSortedArrays(vector<int>&nums1, vector<int>&nums2) {
        
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        
        int x = nums1.size();
        int y = nums2.size();
        
        int start = 0;
        int end = x;
        
        while(start<=end){
         
            int partitionX = (start+end)/2;
            int partitionY = (x+y+1)/2 - partitionX;
         
            int leftMaxX = (partitionX==0)?INT_MIN:nums1[partitionX-1];
            int RightMinX = (partitionY==x)?INT_MAX:nums1[partitionX];
            
            int leftMaxY = (partitionY==0)?INT_MIN:nums2[partitionY-1];
            int RightMinY = (partitionY==y)?INT_MAX:nums2[partitionY];
            
            if(leftMaxY<=RightMinX && leftMaxX<=RightMinY){
                if((x+y)%2!=0) return (double)max(leftMaxX,leftMaxY);
                return (double)(max(leftMaxX,leftMaxY)+min(RightMinX,RightMinY))/2;    
            }
            
            else if(leftMaxY>RightMinX ){
                start=partitionX+1;
            }
            else{
                end=partitionX-1;
            }
            
        }
        return -1;
    }
  
int main()  
{ 

    //112233 4 456789
    vector<int> nums1  = {1,2,2,5};
    vector<int> nums2  = {1,7,8,9};
    cout<<findMedianSortedArrays(nums1,nums2);
  
  
  
    return 0;  
}  