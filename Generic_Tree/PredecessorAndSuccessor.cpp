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

Treenode<int>* predecessor;
Treenode<int>* successor;
int state=0;
void PredeSuccess(Treenode<int>* root,int data)
{
    if(state==0)
    {
        if(root->data==data)
            state=1;
        else
            predecessor=root;
    }
    else if(state==1)
    {
        successor=root;
        state=2;
    }
    for(Treenode<int>* node: root->children)
    {
        PredeSuccess(node,data);
    }
}

int main() {
    vector<int> arr = {1,2,3,-1,4,-1,-1,5,-1,6};
    Treenode<int>* root = Create(arr);
	display(root);
	cout<<endl;
	cout<<"Enter the key: ";
	int data;
	cin>>data;
    PredeSuccess(root,data);
    if(predecessor==NULL)
        cout<<"Predecessor is null\n";
    else
        cout<<"Predeccessor: "<<predecessor->data<<endl;
    if(successor==NULL)
        cout<<"successor is null\n";
    else
        cout<<"successor: "<<successor->data<<endl;
    cout<<endl;
	return 0;
}


