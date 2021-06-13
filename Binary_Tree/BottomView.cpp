

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

void BottomView(BinaryTreeNode<int>* root)
{
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    if(!root) return;
    q.push({root,0});
    while(!q.empty())
    {
        BinaryTreeNode<int>* t =q.front().first;
        int h = q.front().second;
        q.pop();
        mp[h]=t->data;
        if(t->left) q.push({t->left,h-1});
        if(t->right) q.push({t->right,h+1});
    }
    for(auto x:mp)
        cout<<x.second<<" ";
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    BottomView(root);
}
// 10 20 30 40 50 60 70 80 -1 -1 90 100 -1 -1 110 -1 -1 -1 -1 -1 -1 120 -1 -1 -1



