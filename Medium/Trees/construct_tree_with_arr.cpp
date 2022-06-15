// GeeksForGeeks
// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

#define fio                                 \
    freopen("../../input.txt", "r", stdin); \
    freopen("../../output.txt", "w", stdout);
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#include <bits/stdc++.h>
using namespace std;



class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Time : O(n^2) 

void Util(Node *root, int parent[], int N)
{
    if (root == NULL)
        return;
    for (int i = 0; i < N; i++)
    {
        if (parent[i] == root->data)
        {
            Node *newNode = new Node(i);
            if (root->left == NULL)
                root->left = newNode;
            else
                root->right = newNode;
        }
    }
    Util(root->left, parent, N);
    Util(root->right, parent, N);
}

Node* createTree(int parent[], int N)
{
    Node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        if (parent[i] == -1)
            root = new Node(i);
    }
    Util(root, parent, N);
    return root;
}


void inorderRecursive(Node* root){
    if(root!=NULL){
        inorderRecursive(root->left);
        cout<<root->data<<" ";
        inorderRecursive(root->right);
    }
}

int main()
{
    fio int n;
    cin >> n;
    int arr[n];
    FOR(i, 0, n)
        cin >> arr[i];
    Node *root = NULL;
    root = createTree(arr,n);
    inorderRecursive(root);
    return 0;
}