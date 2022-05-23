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

Node* insertNode(Node *root,string x,queue<Node*> &q){
    if(x!="N"){
        Node* newNode = new Node(stoi(x));
        if(root==NULL) root=newNode;
        else if(q.front()->left==NULL) q.front()->left=newNode;
        else{
            q.front()->right=newNode;
            q.pop();
        }
        q.push(newNode);
    }
    return root;
}

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

void inorderRecursive(Node* root){
    if(root!=NULL){
        inorderRecursive(root->left);
        cout<<root->data<<" ";
        inorderRecursive(root->right);
    }
}

void inorderIterative(Node* root){
    stack<Node*> s;
    while(true){
        if(root){
            s.push(root);
            root = root->left;
        }
        else{
            if(s.empty()) break;
            root = s.top();
            s.pop();
            cout<<root->data<<" ";
            root = root->right;
        }
    }
}

void preorderRecursive(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void preorderIterative(Node* root){
    stack<Node*> s;
    while(true){
        if(root){
            cout<<root->data<<" ";
            root = root->left;
        }
        else{
            if(s.empty()) break;
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    string str;
    Node* root = NULL;
    getline(cin,str);
    if(str.length()!=0 || str[0]!='N'){
        vector<string> nodeData;
        istringstream iss(str);
        for(string str;iss>>str;) nodeData.push_back(str);
        queue<Node*> q;
        for(int i=0;i<nodeData.size();i++){
            root = insertNode(root,nodeData[i],q);
        }
    } 
    //printLevelOrder(root);
    //inorderRecursive(root);
    //inorderIterative(root);
    //preorderRecursive(root);
    return 0;
}