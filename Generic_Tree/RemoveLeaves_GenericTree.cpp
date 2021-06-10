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

Treenode<int>* RemoveLeaves(Treenode<int>* root)
{
    if(root==NULL)
        return NULL;
    if(root->children.size()==0)
    {
        delete root;
        return NULL;
    }
    for(int i=0;i<root->children.size();i++)
    {
        Treenode<int>* child = root->children[i];
        if(child->children.size()==0)
        {
            delete child;
            for(int j=i;j<root->children.size()-1;j++)
            {
                root->children[j]=root->children[j+1];
            }
            root->children.pop_back();
            i--;
        }
    }
    for(int i=0;i<root->children.size();i++)
    {
        root->children[i] = RemoveLeaves(root->children[i]);
    }
    return root;

}

int main() {
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
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
	display(root);
	cout<<endl;
    root=RemoveLeaves(root);
    display(root);
	return 0;
}




