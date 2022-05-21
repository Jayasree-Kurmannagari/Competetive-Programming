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
    printLevelOrder(root);
    return 0;
}