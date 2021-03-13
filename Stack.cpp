#include<bits/stdc++.h>
using namespace std;

//Macros #define <accronyms> <real-name>
#define ll long long
#define ar array

template <typename Object>
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
    
    void add(Object &&x){
      this->v.push_back(move(x));
      ++top;
    }
    void add(Object &x){
      this->v.push_back(x);
      ++top;
    }
    void print(){
      int temp=this->top;
      while(temp>-1){
        cout<<this->v[temp--]<<" ";
      }
    }
    
};


int main() {
  Stac_k<int>st;
  st.add(100);
  st.add(200);
  st.add(300);
  st.add(400);
  st.add(500);
  //st.print();
  Stac_k<int>tt = st;
  //tt.print();
  Stac_k<char>x;
  char a='x',b='y',c='z',d='y',e='x';
  x.add(a);
  x.add(b);
  x.add(c);
  x.add(d);
  x.add(e);
  x.print();
  
return 0; 
} 
