// https://youtu.be/amG7xun8k4w
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// struct Node{
//   int data;
//   std::vector<Node* > children;
// };
template<typename T>
class Treenode{
  public:
  T data;
  vector<Treenode<T>*> children;
  Treenode(T data)
  {
      this->data=data;
  }
  ~Treenode()
  {
      for(int i=0;i<children.size();i++)
      {
          delete children[i];
      }
  }
};
Treenode<int>* Create(vector<int>& arr)
{
    Treenode<int>* root;
	std::stack<Treenode<int>* > st;
	for(int i=0;i<arr.size();i++)
	{
	    if(arr[i]==-1)
	    st.pop();
	    else
	    {
	        Treenode<int>* t = new Treenode<int>(arr[i]);
	       // t->data = arr[i];
	        if(st.size()>0)
	        {
	            st.top()->children.push_back(t);
	        }
	        else
	        {
	            root=t;
	        }
	        st.push(t);
	    }
	}
	return root;

}
void display(Treenode<int>* root)
{
    cout<<root->data<<"->";
    for(Treenode<int>* node: root->children)
    {
        cout<<node->data<<",";
    }
    cout<<".\n";
    for(Treenode<int>* node: root->children)
    {
        display(node);
    }
}

bool AreMirror(Treenode<int>* root1,Treenode<int>* root2)
{
    if(root1->children.size()!=root2->children.size())
    return false;

    for(int i=0;i<root1->children.size();i++)
    {
        int j = root1->children.size()-1-i;
        Treenode<int>* n = root1->children[i];
        Treenode<int>* m = root2->children[j];
        if(AreMirror(n,m)==false)
            return false;
    }
    return true;
}

bool AreSymmetric(Treenode<int>* root)
{
    return AreMirror(root,root);
}
int main() {
    vector<int> arr = {1,2,3,-1,4,-1,-1,5,-1,6};
    Treenode<int>* root = Create(arr);
	display(root);
	cout<<endl;
    bool ans = AreSymmetric(root);
    if(ans)
        cout<<"Symmetric image\n";
    else
        cout<<"Not symmetric image\n";
    cout<<endl;
	return 0;
}

