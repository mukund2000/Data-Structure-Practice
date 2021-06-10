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

void ZigZag(Treenode<int>* root)
{
    stack<Treenode<int>* > ms;
    stack<Treenode<int>* > cs;
    ms.push(root);
    int level=1;
    while(ms.size()>0)
    {
        Treenode<int>* node = ms.top();
        cout<<node->data<<" ";
        ms.pop();
        if(level%2==1)
        {
            for(int i=0;i<node->children.size();i++)
            {
                cs.push(node->children[i]);
            }
        }
        else
        {
            for(int i=node->children.size()-1;i>=0;i--)
            {
                cs.push(node->children[i]);
            }
        }
        if(ms.size()==0)
        {
            ms.swap(cs);
            level++;
            cout<<endl;
        }
    }
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
	ZigZag(root);
	return 0;
}



