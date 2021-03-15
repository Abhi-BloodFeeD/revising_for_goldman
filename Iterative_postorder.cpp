#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node (){};
  Node(int data){
    this->data = data;
  }
};

class BST{
  private:
    Node*root;
  public:
    BST(){
      root=NULL;
    }
    void insert(int data){
      
      if(!this->root){
        this->root =  new Node(data);
        return;  
      }
      
      Node* temp = this->root;
      Node* follow = NULL;
      while(temp){
        follow = temp;
        if(data < temp->data) 
          temp = temp->left;    
        else 
          temp = temp->right; 
      }
      
      if(data<follow->data)
        follow->left = new Node(data);
      else  
        follow->right = new Node(data); 
     }//insert end;
    Node* getRoot(){return root;}
};

void print_recursive(Node* root,stack<Node*> &st){
  if(!root)return;
  
  st.push(root->left);
  Node* temp1 = st.top();st.pop();
  print_recursive(temp1,st);

  st.push(root->right);
  Node* temp2 = st.top();st.pop() ;
  print_recursive(temp2,st);
  
  cout<<root->data<<endl;

}


int main() {
  stack<Node*>st;
  BST bst;
  bst.insert(4);
  bst.insert(5);
  bst.insert(3);
  bst.insert(2);
  bst.insert(1);
  bst.insert(7);
  bst.insert(8);
  st.push(bst.getRoot());
  print_recursive(st.top(),st);
return 0; 
} 

// //                       4
//                         / \
//                       2   5
//                       / \   \
//                      1   3   7
//                               \
//                                8