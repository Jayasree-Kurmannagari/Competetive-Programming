#include<bits/stdc++.h>
using namespace std;

// class Node{
//     public:
//         int data;
//         Node *left,*right;
//     Node(int val){
//         data=val;
//         left=NULL;
//         right=NULL;
//     }
// };
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

Node* buildTree(Node *root,string data,queue<Node*> &q,int i){
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

Node* search(Node *root, int key){
    if(root==NULL || root->data == key) return root;
    else if(root->data>key) return search(root->left,key);
    else return search(root->right,key);
}


Node* inorderPredecessor(Node *root,Node *key){
    Node *result;
    while(root){
        if(root->data<key->data) {
            result = root;
            root=root->right;
        }
        else root = root->left;
    }
    return result;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    Node *root=NULL;
    string str;
    getline(cin,str);
    if(str.length() || str[0]!='N'){
        vector<string> nodeData;
        istringstream iss(str);
        for(string s;iss>>s;) nodeData.push_back(s);
        queue<Node*> q;
        for(int i=0;i<nodeData.size();i++) root=buildTree(root,nodeData[i],q,i);
    }
    int key;cin>>key;
    Node *k = search(root,key);
    Node *ans = inorderPredecessor(root,k);
    cout<<ans->data<<endl;
    return 0;
}