//https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1/

#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    int freq;

    MinHeapNode *left,*right;

    MinHeapNode(char data,int freq){
        left=right=NULL;
        this->data = data;
        this->freq = freq;
    }

};


struct compare{
    bool operator()(MinHeapNode* node1,MinHeapNode* node2){
        return node1->freq > node2->freq;
    }
};

void printPQ(priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> gq)
{
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top()->data << "->" << g.top()->freq;
        g.pop();
        cout<<endl;
    }
    cout<<endl;
}

void printCodes(struct MinHeapNode* root,string s){
    if(!root) return;

    if(root->data != '$') cout<<root->data<<" : "<<s<<endl;
    printCodes(root->left,s+"0");
    printCodes(root->right,s+"1");
}

void HuffmanCodes(char data[],int freq[],int n){
    MinHeapNode *left,*right,*top;
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> p;
    for(int i=0;i<n;i++) p.push(new MinHeapNode(data[i],freq[i]));
    while(p.size()!=1){
        left = p.top();
        p.pop();
        right = p.top();
        p.pop();
        top = new MinHeapNode('$',left->freq+right->freq);
        top->left = left;
        top->right = right;
        p.push(top);
        //printPQ(p);
    }
    printCodes(p.top(),"");
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
    #endif
    int n;cin>>n;
    char data[n];
    int freq[n];
    for(int i=0;i<n;i++) cin>>data[i];
    for(int i=0;i<n;i++) cin>>freq[i];
    HuffmanCodes(data,freq,n);
    return 0;
}