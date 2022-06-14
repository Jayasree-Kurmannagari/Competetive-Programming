//Leetcode
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left=right=NULL;
    }
};

Node* buildTree(Node* root, string x,queue<Node*> &q,int i){
    if(x!="N"){
        Node* newNode = new Node(stoi(x));
        if(root==NULL) root=newNode;
        else if(q.front()->left==NULL && i%2) q.front()->left = newNode;
        else if(i%2==0){
            q.front()->right=newNode;
            q.pop();
        }
        q.push(newNode);
    }
    return root;
}

void calculate_distance_from_root(Node *root,map<int,map<int,multiset<int>>>& mp,int d,int level){
    if(root==NULL) return;
    mp[d][level].insert(root->data);
    calculate_distance_from_root(root->left,mp,d-1,level+1);
    calculate_distance_from_root(root->right,mp,d+1,level+1);
}
vector<vector<int>> verticalOrderTraversal(Node *root){
    vector<vector<int>> res;
    map<int,map<int,multiset<int>>> mp;
    int distance_from_root =0,level=0;
    calculate_distance_from_root(root,mp,distance_from_root,level);
    for(auto x:mp){
        vector<int> tmp;
        for(auto p:x.second){
            for(auto l:p.second) tmp.push_back(l);
        }
        res.push_back(tmp);
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
    Node* root = NULL;
    if(str[0]!='N' && str.length()!=0){
        istringstream iss(str);
        vector<string> nodeData;
        for(string s;iss>>s;) nodeData.push_back(s);
        queue<Node*> q;
        for(int i=0;i<nodeData.size();i++) root = buildTree(root,nodeData[i],q,i);
    }
    vector<vector<int>> ans;
    ans = verticalOrderTraversal(root);
    for(auto x:ans){
        for(auto p:x) cout<<p<<" ";
        cout<<"\n";
    };
    return 0;
}