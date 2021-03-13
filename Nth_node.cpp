#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

/*
class Node{
  private :
    int data;
    Node *next;
  public:
    Node(){
        next = NULL;
    }
    
    Node(int da){
        data = da;
        next = NULL;
    }
    int value(){
      return data;
    }
};
*/
struct Node{
  int data;
  Node *next=NULL;
};

class LinkedList{
  private:
    Node *head;
  public:
    LinkedList(){
      head = NULL;
    }
    LinkedList(Node *x){
      Node *temp = head;
      while(x){
        temp = new Node;
        temp->data = x->data;  
        temp=temp->next;
        x=x->next;
      }
    }
  void add_node(int n){
    Node* x = new Node;
    x->data = n;
    if(head==NULL){
      head = x;
      return;
    }
    Node *temp = head;
    while(temp && temp->next){
      temp=temp->next;
    }
    temp->next = x;
    return;
    }
  void print_ll(){
    Node * temp = head;
    while(temp){
      cout<<temp->data<<endl;
      temp=temp->next;
      }
    }
  void reverse(){
    Node *prev=NULL,*cur=head;
    //1->2->3//
    //NULL->1->2<-3->NULL//
    //only two element//
    while(cur){
      Node *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
      //delete(temp);
    }
    head = prev;
    return;
  }
  int length_list(){
    Node* temp=head;
    int score=0;
    //1->2->2->3->3;
    while(temp){
      temp=temp->next;
      score++;
    }
    return score;
  }
  bool add_next(int n,int d){
    Node *temp =head;
    while(temp && (temp->data)!=(n)){
      temp = temp->next;
    }
    if(temp){
      Node *rep = temp->next;
      
      Node *ptr = new Node;
      ptr->data =d;
      
      temp->next = ptr;
      ptr->next = rep;
      return true;
    }
    return false;
  }
  Node * giveHead(){
    return head;
  }
  void reverse_recursive(Node*h){
    if(!h) return;
    reverse_recursive(h->next);
    cout<<h->data<<endl;
    return;
  }

  Node* reverse_batch(int size){
  stack<Node*>st;
  Node * temp = this->head;
  Node* result=NULL;
  while(temp){
    int count = 0;
    while(temp && count<size){
      st.push(temp);
      temp=temp->next;
      count++;
      }
    while(!st.empty()){
      if(!result){
        result = st.top();
        this->head = result;
        st.pop();
      }
      else{
        result->next = st.top();
        result=result->next;  
        st.pop();
      }
      }
    }
    result->next = NULL;
    return head;
  } 
};
//NULL->1->2->3->NULL//
///   1    ///
//NULL<-head , NULL<-temp//


int main() {
  LinkedList ptr;
  ptr.add_node(1);
  ptr.add_node(2);
  ptr.add_node(3);
  ptr.add_node(4);
  //ptr.print_ll();
  LinkedList xyz = ptr;
  //xyz.print_ll();
  //xyz.reverse();
  //cout<<xyz.length_list()<<"\n"<<endl;
  xyz.print_ll();
  cout<<"--- \n";
  xyz.reverse_batch(2);
  xyz.print_ll();
  
return 0; 
} 
