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
      delete(temp);
    }
    head = prev;
  }
};

int main() {
  LinkedList ptr;
  ptr.add_node(1);
  ptr.add_node(2);
  ptr.add_node(3);
  ptr.add_node(4);
  //ptr.print_ll();
  LinkedList xyz = ptr;
  //xyz.print_ll();
  xyz.reverse();
  xyz.print_ll();

return 0; 
} 
