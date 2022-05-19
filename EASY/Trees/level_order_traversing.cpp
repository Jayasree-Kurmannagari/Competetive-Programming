//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/level-order-traversal/1#

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left,*right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(Node* node){
    queue<Node*> q;
    if(node==NULL) return;
    q.push(node);
    while(q.empty()==false){
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}

Node* insertNode(Node *root,int x,queue<Node*> &q){
    Node* newNode = new Node(x);
    if(root==NULL) root=newNode;
    else if(q.front()->left==NULL) q.front()->left=newNode;
    else{
        q.front()->right=newNode;
        q.pop();
    }
    q.push(newNode);
    return root;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root = NULL;
    queue<Node*> q;
    for(int i=0;i<n;i++){
        root = insertNode(root,arr[i],q);
    }
    // Node* root = new Node(1);
    // root->left = new Node(3);
    // root->right = new Node(4);
    // root->left->left = new Node(7);
    // root->left->right = new Node(2);
    printLevelOrder(root);
    return 0;
}