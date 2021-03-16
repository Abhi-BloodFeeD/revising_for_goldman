#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mod = 1e9+7;
const int mxN = 1e6;
const int N = 2e5;

struct Node{
  int data;
  Node* left_child;
  Node* right_child;
  Node(){}
  Node(int d){
    this->data = d;
  }
};
class Binary_Tree{
  private:
    Node* root;
  public:
    Binary_Tree(){};
    Binary_Tree(Node *r){
      this->root = r; 
    }
    Binary_Tree(int x){
      this->root = new Node(x);
    }
    void push_child(int d){
      Node* child = new Node(d);
      Node * runner = root;
      Node * follower = NULL; 
      while(runner){
         follower = runner;
         if(d>runner->data){
           runner=runner->right_child;
         }
         else
          runner=runner->left_child;
      }
      if(!root){
        root = child;
        return;
      }
      if(d>follower->data)follower->right_child = child;
      else follower->left_child = child;
    }
    void level_order_traversal(Node *g){
       queue<Node*> q;
       q.push(g);
       while(!q.empty()){
         Node* T=q.front();
         cout<<T->data<<endl;
         if(T->left_child)
          q.push(T->left_child);
         if(T->right_child)
          q.push(T->right_child);
         q.pop();
       }  
       return;
    }
    Node * root_node(){
      return this->root;
    }
};

int main() {
  Binary_Tree B;
  B.push_child(10);
  B.push_child(8);
  B.push_child(9);
  B.push_child(7);
  B.push_child(12);
  B.push_child(11);
  B.push_child(13);
  //B.push_child(10);
  B.level_order_traversal(B.root_node());
  
return 0; 
} 
