//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/#

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

Node* insertNode(Node *root,string data,queue<Node*> &q,int i){
    if(data!="N"){
        Node* newNode = new Node(stoi(data));
        if(root==NULL) root=newNode;
        else if(q.front()->left==NULL && i%2) q.front()->left = newNode;
        else if(i%2==0){
            q.front()->right = newNode;
            q.pop();
        }
        q.push(newNode);
    }
    return root;
}

Node* search(Node* root,int key){
    if(root==NULL || root->data==key) return root;
    if(root->data>key) return search(root->left,key);
    else return search(root->right,key);
}

Node* inorderSuccessor(Node *root,Node *key){
    Node* result;
    while(root){
        if(root->data<=key->data) root=root->right;
        else{
            result = root;
            root = root->left;
        }
    }
    return result;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    string str;
    getline(cin,str);
    Node* root = NULL;
    Node* curr = root;
    if(str.length() || str[0]!='N'){
        vector<string> nodeData;
        istringstream iss(str);
        for(string s;iss>>s;) nodeData.push_back(s);
        queue<Node*> q;
        for(int i=0;i<nodeData.size();i++) root = insertNode(root,nodeData[i],q,i);
    }
    int key;cin>>key;
    Node* k = search(root,key);
    Node* result = inorderSuccessor(root,k);
    cout<<result->data<<endl;
    return 0;
}