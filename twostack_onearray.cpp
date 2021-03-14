#include<bits/stdc++.h>
using namespace std;

const int nxM = 1e3;
template<class T>
class Stack{
  private:
    int size;
    T v[nxM];
    int top1,top2;
  public:
    // constructor 
    Stack(){
      this->top1=-2;
      this->top2=-1;
    }
    
    void push1(T &x){
      this->top1+=2;
      this->v[top1]=x;
    }
    void push1(T &&x){
      this->top1+=2;
      this->v[top1]=move(x);
    }
    
    void push2(T &x){
      this->top2+=2;
      this->v[top2]=x;
    }
    void push2(T &&x){
      this->top2+=2;
      this->v[top2]=move(x);
    }
    //pop function
    void pop1(){
      if(this->top1<0)return;
      this->top1-=2;
    }    
    void pop2(){
      if(this->top2<0)return;
      this->top2-=2;
    }
    //
    void print(){
      while(this->top1>0 && this->top2>0){
        cout<<this->v[top1]<<" "<<this->v[top2]<<" ";
        top1-=2,top2-=2;
      }
      if(this->top1>0){
        while(this->top1>0){
          cout<<this->v[top1]<<" ";
          top1-=2;
        }
      }
      if(this->top2>0){
        while(this->top2>0){
          cout<<this->v[top2]<<" ";
          top2-=2;
        }
      }
    }

   
};
int main() {
  Stack<int> s;
  s.push1(10);
  s.push2(10);
  s.push1(20);
  s.push2(20);
  s.push1(30);
  s.push2(40);
  s.push1(50);
  s.print();
  
  
return 0; 
} 
