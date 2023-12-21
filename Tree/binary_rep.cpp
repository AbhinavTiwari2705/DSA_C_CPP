#include <iostream>
using namespace std;
 
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder_travel(Node *root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        preorder_travel(root->left);
        preorder_travel(root->right);
    }
}

void postorder_travel(Node *root){
    if(root==NULL){
        return;
    }
    else{
        postorder_travel(root->left);
        postorder_travel(root->right);
        cout<<root->data<<" ";
    }
}

void inorder_travel(Node *root){
    if(root==NULL){
        return;

    }
    else{
        inorder_travel(root->left);
        cout<<root->data<<" ";
        inorder_travel(root->right);
    }
}

int main(){
    struct Node * root= new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
     
    /*
        1
       / \
      2   3
     / \ / \ 
    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    /*
        1
       / \
      2   3
     / \ / \
    4  5  
    */
   preorder_travel(root);
    cout<<endl;
    postorder_travel(root);
    cout<<endl;
    inorder_travel(root);
    cout<<endl;

    return 0;
}