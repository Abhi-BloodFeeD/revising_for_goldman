#include<bits/stdc++.h>
using namespace std;

//Macros #define <accronyms> <real-name>
#define ll long long
#define ar array

template <class Object>
class Stac_k{
  private:
    vector<Object> v;
    int top;
  public: 
    Stac_k(){
      top = -1;
    }
    Stac_k(Object &a){
      int size=a->top;
      for(int i=0;i<size;i++){
        this->top++;
        this->v.push_back(a->v[i]);
      }
    }
    
    void print(){
      int temp=this->top;
      while(temp>-1){
        cout<<this->v[temp--]<<" ";
      }
    }
    bool isEmpty(){
      if(this->v.size())return true;
      else false;
    }
    //template(typename T)
    void push(Object &x){
      this->v.push_back(x);
      ++top;
    }
    //template(typename T)
    void push(Object &&x){
      this->v.push_back(move(x));
      ++top;
    }
    
};

void print_break(){
  cout<<"------\n";
}
int main() {
  Stac_k<int>st;
  st.push(100);
  st.push(200);
  st.push(300);
  st.push(400);
  st.push(500);
  st.print();
  print_break();
  Stac_k<int>tt = st;
  tt.print();
  print_break();
  Stac_k<char>x;
  char a='x',b='y',c='z',d='y',e='x';
  x.push(a);
  x.push(b);
  x.push(c);
  x.push(d);
  x.push(e);
  x.print();
  print_break();
  
return 0; 
} 
