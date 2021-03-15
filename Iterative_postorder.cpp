#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

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
      Node* temp = root;
      Node* follow = NULL;
      while(temp){
        if(data < temp->data) 
        {
          follow = temp;
          temp = temp->left;    
        }
        else {
          follow = temp;
          temp = temp->right; 
        }
      }
      if(follow->data<data)
        follow->left = new Node(data);
      else  
        follow->right = new Node(data); 
      
      
      
     }//insert end;
    Node* getRoot(){return root;}
};

void print_recursive(Node* root,stack<Node*> &st){
  if(!root)return;
  
  st.push(root->left);
  st.push(root->right);
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
  while(!st.empty()){
    st.push(left)
  }
return 0; 
} 
