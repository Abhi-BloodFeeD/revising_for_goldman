#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mod = 1e9+7;
const int mxN = 1e3;
const int N = 2e5;

template<class T>
class Queue{
  private:
    int location;
    T array[mxN];
  public:
    Queue(){
      location = -1;
    }
    Queue(int s){
      location = -1;
    }
    void push(T x){
      array[++location]=x;
      return;
    }
    void pop(){
      if(location<0){
        cout<<"ERROR \nALREADY EMPTY QUEUE\n";  
        return;
      }
      --location;
      return;
    }

    T front(){
      return array[location];
    }
    
    bool empty(){
      return location<0;
    }
    
    void print(){
      for(int i=0;i<=location;i++)
        cout<<array[i]<<"\n";
    }
    
};

int main() {
Queue<int> q;
if(q.empty())
  cout<<"EMPTY\n";
q.push(1100);
q.push(1200);
q.push(1300);
q.push(1400);
q.push(1500);
q.print();  
if(!q.empty())
  cout<<"NOT-EMPTY\n";
return 0; 
} 

