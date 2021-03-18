#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mod = 1e9+7;
const int mxN = 1e6;
const int N = 2e5;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(){};
  Node(int d){
    this->data=d;
  }
};

Node bst_convert(list<int>&L){
  auto it = L.begin();
  Node v_root = Node(*it);
  queue<Node>q;
  q.push(v_root);
  while(it!=L.end()){
    Node root = q.front();
    q.pop();
    if(++it!=L.end()){
      Node left = Node(*it);
      q.push(left);
    }
    if(++it!=L.end()){
      Node right = Node(*it);
      q.push(right);
    }
    // it++;
  }
  return v_root;
}
 void printINORDER(Node root){
   if(root.left && root.right){
     cout<<root.data<<endl;   
     return;
   }
   printINORDER(*root.left);
   printINORDER(*root.right);
   return;
   
 }

int main() {
  list<int> l;
  auto x=l.begin();
  l.push_back(10);
  l.push_back(12);
  l.push_back(15);
  l.push_back(25);
  l.push_back(30);
  l.push_back(36);
  printINORDER(bst_convert(l));
  
  
return 0; 
} 
