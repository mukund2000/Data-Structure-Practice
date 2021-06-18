#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
    if(root==NULL)
        return;
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
        cout<<pending.front()->data<<":";
        if(pending.front()->left==NULL){
            cout<<"L:-1,";
        }
        if(pending.front()->left!=NULL){
            cout<<"L:"<<pending.front()->left->data<<",";
            pending.push(pending.front()->left);
        }
        if(pending.front()->right==NULL){
            cout<<"R:-1";
        }
        if(pending.front()->right!=NULL){
            cout<<"R:"<<pending.front()->right->data;
            pending.push(pending.front()->right);
        }
        cout<<endl;
        pending.pop();
    }
	// Write your code here
}

BinaryTreeNode<int>* LCA(BinaryTreeNode<int>* root,int n1,int n2)
{
    if(!root) return NULL;
    if(root->data==n1 or root->data==n2)
    return root;
    BinaryTreeNode<int>* l = LCA(root->left,n1,n2);
    BinaryTreeNode<int>* r = LCA(root->right,n1,n2);
    if(l and r) return root;
    if(l) return l;
    else
    return r;
}

int solve(BinaryTreeNode<int>* root,int n)
{
    if(!root) return 0;
    if(root->data==n) return 1;
    int a = solve(root->left,n);
    int b = solve(root->right,n);
    if(!a and !b) return 0;
    else
    return a+b+1;
}

int Distance(BinaryTreeNode<int>* root,int s,int d)
{
    BinaryTreeNode<int>* ans = LCA(root,s,d);
    int a = solve(ans,s);
    int b = solve(ans,d);
    return a+b-2;
}
int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    int n1,n2;
    cin>>n1>>n2;
    cout<<"Distance between two nodes n1 and n2 is: "<<Distance(root,n1,n2)<<endl;
}
// 10 20 30 40 50 60 70 80 -1 -1 90 100 -1 -1 110 -1 -1 -1 -1 -1 -1 120 -1 -1 -1







