
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

vector<int> ZigZag(BinaryTreeNode<int>* root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int f=1;
    while(!q.empty())
    {
        vector<int> temp;
        int sz= q.size();
        while(sz--)
        {
            BinaryTreeNode<int>* t = q.front();
            q.pop();
            temp.push_back(t->data);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(f%2==0) reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
            ans.push_back(temp[i]);
        f+=1;
    }
    return ans;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    vector<int> ans = ZigZag(root);
    for(int a:ans)
        cout<<a<<" ";
}
// 10 20 30 40 50 60 70 80 -1 -1 90 100 -1 -1 110 -1 -1 -1 -1 -1 -1 120 -1 -1 -1




