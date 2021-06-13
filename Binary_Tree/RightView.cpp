
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

void RightView(BinaryTreeNode<int>* root)
{
    queue<BinaryTreeNode<int>* > q;
    if(!root) return;
    q.push(root);
    while(!q.empty())
    {
        int sz= q.size();
        BinaryTreeNode<int>* t;
        while(sz--)
        {
            t = q.front();
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        cout<<t->data<<" ";
    }

}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    RightView(root);
}
// 10 20 30 40 50 60 70 80 -1 -1 90 100 -1 -1 110 -1 -1 -1 -1 -1 -1 120 -1 -1 -1


