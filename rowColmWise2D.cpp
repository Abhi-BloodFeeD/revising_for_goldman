#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define row 5
#define colm 5

bool search(int a[row][colm], int xs,int xf,int ys,int yf,int tofind){
	int x_mid = (xs+xf)/2 ;
	int y_mid = (ys+yf)/2;

	if(a[x_mid][y_mid]==tofind)
		return true;
	if(xs==xf && ys==yf)
		return false;
	if(a[x_mid][y_mid]>tofind){
		return search(a,xs,xf,ys,y_mid,tofind)||search(a,xs,x_mid,y_mid,yf,tofind);	
	}
	if(a[x_mid][y_mid]<tofind){
		return search(a,xs,xf,y_mid,yf,tofind)||search(a,x_mid,xf,ys,y_mid,tofind);	
	}
	return false;
}

int main(){
	int a[row][colm] = {{1,2,3,4,5},
			    {2,3,4,5,6},
          {4,5,6,7,8},
			    {5,6,7,8,9},
			    {8,9,10,11,12}};		    
	search(a,0,row-1,0,colm-1,12)?cout<<"FOUND\n":cout<<"NOT PRESENET\n";
}