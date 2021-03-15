#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Node
{
  T data;
  Node<T> *next;

  Node(){}

  Node(T &a){
    this->data = a;
  }
  Node(T &&a){
    this->data = move(a);
  }
};

template<class T>
class Stack_Linked{
  private:
    Node<T>* head;
  public:
   
    Stack_Linked(){}
    Node<T>* gethead(){
      return this->head;
    }
    void add(T data){
      Node<T>* temp = gethead();
      while(temp && temp->next){
        //cout<<"ERROR1"<<endl;
        temp=temp->next;
      }
      //cout<<"MERA MAUKA NAHI AYA\n";
      Node<T>* n = new Node<T>(data);
      if(!head){
        head=n;
        return;
      }
      temp->next = n;
      temp = temp->next;
      return;
    }
    void print(){
      Node<T>*t = this->head;
      while(t){
        cout<<t->data<<endl;
        t=t->next;
      }
    }
    Stack_Linked<T> operator=(Stack_Linked<T>z){
      Stack_Linked<T> c;
      c.head = z.gethead();
      return c;
    }
    
};
template<class T>
Stack_Linked<T> merger(Stack_Linked<T> &a,Stack_Linked<T> &b){
  Node<T>*temp = a.gethead();
  if(!temp)return b;
  while(temp && temp->next)
    temp=temp->next;
  temp->next = b.gethead();
  return a;
}

int main() {
  Stack_Linked<int> a;
  Stack_Linked<int> b;
  Stack_Linked<int> c;
  
  a.add(1);
  a.add(2);
  a.add(3);
  a.add(4);
  b.add(4);
  b.add(3);
  b.add(2);
  b.add(1);
  c=merger(a,b);
  c.print();
return 0; 
} 
