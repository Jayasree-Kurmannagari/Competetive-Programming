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

void inorderMorris(Node* root){
    if(root==NULL) return;
    Node *current,*prev;
    current = root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current=current->right;
        }
        else{
            prev = current->left;
            while(prev->right!=NULL && prev->right!=current) prev=prev->right;
            if(prev->right==NULL){
                prev->right = current;
                current = current->left;
            }
            else{
                prev->right = NULL;
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
}

void preorderMorris(Node* root){
    if(root==NULL) return;
    Node *current,*prev;
    current = root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current=current->right;
        }
        else{
            prev = current->left;
            while(prev->right!=NULL && prev->right!=current) prev=prev->right;
            if(prev->right==NULL){
                prev->right = current;
                cout<<current->data<<" ";
                current = current->left;
            }
            else{
                prev->right = NULL;
                current=current->right;
            }
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

void postorderRecursive(Node* root){
    if(root!=NULL){
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout<<root->data<<" ";
    }
}

void postorderIterative(Node* root){
    stack<Node*> s;
    while(true){
        while(root){
            s.push(root);
            s.push(root);
            root=root->left;
        }
        if(s.empty()) return;
        root = s.top();
        s.pop();
        if(!s.empty() && s.top()==root) root=root->right;
        else{
            cout<<root->data<<" ";
            root=NULL;
        }
    }
}

void postorderMorris(Node* root){
    vector<int> v;
    Node *current,*prev;
    current = root;
    while(current){
        if(current->right==NULL){
            v.push_back(current->data);
            current = current ->left;
        }
        else{
            prev = current->right;
            while(prev->left && prev->left!=current) prev = prev->left;
            if(prev->left==NULL){
                prev->left = current;
                v.push_back(current->data);
                current = current->right;
            }
            else {
                prev->left = NULL;
                current = current->left;
            }
        }
    }
    reverse(v.begin(),v.end());
    for(auto x:v) cout<<x<<" ";
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
    //inorderMorris(root);
    //preorderRecursive(root);
    //preorderMorris(root);
    //postorderRecursive(root);
    //postorderIterative(root);
    postorderMorris(root);
    return 0;
}