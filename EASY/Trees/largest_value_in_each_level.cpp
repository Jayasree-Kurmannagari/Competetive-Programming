//GeeksForGeeks
//https://practice.geeksforgeeks.org/problems/largest-value-in-each-level/1/#

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left,*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* buildTree(Node *root,string x,queue<Node*> &q,int i){
    if(x!="N"){
        Node *newNode = new Node(stoi(x));
        if(root==NULL) root=newNode;
        else if(q.front()==NULL && i%2) q.front()->left = newNode;
        else if(i%2==0) {
            q.front()->right = newNode;
            q.pop();
        }
        q.push(newNode);
    }
    return root;
}


vector<int> largestValue(Node* root){
    if(root==NULL) return {};
    vector<int> res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> tmp(size);
        for(int i=0;i<size;i++){
            Node *temp = q.front();
            q.pop();
            tmp.push_back(temp->data);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        res.push_back(*max_element(tmp.begin(),tmp.end()));
    }
    return res;
}


int main(){
     #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    string str;
    getline(cin,str);
    Node *root = NULL;
    if(str.length() || str[0]!='N'){
        vector<string> nodeData;
        istringstream iss(str);
        for(string s;iss>>s;) nodeData.push_back(s);
        queue<Node*> q;
        for(int i=0;i<nodeData.size();i++) root = buildTree(root,nodeData[i],q,i);
    }
    vector<int> v = largestValue(root);
    for(auto x:v) cout<<x<<" ";
    return 0;
}