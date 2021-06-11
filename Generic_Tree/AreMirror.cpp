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

int main() {
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    Treenode<int>* root1 = Create(arr);
	display(root1);
	cout<<endl;
	vector<int> arr2 = {1,2,5,-1,6,-1,-1,3,7,9,-1,10,-1,-1,8,-1,-1,4,11,-1,-1,-1};
	Treenode<int>* root2 = Create(arr2);
	display(root2);
	cout<<endl;
    bool ans = AreMirror(root1,root2);
    if(ans)
        cout<<"Mirror image\n";
    else
        cout<<"Not mirror image\n";
    cout<<endl;
	return 0;
}
