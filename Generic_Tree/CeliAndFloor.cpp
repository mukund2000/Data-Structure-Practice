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

	int Floor = INT_MIN;
    int Ceil = INT_MAX ;
void CeilFloor(Treenode<int>* root,int data)
{
    if(root->data>data)
    {
        if(root->data<Ceil)
        {
            Ceil = root->data;
        }
    }
    if(root->data<data)
    {
        if(root->data>Floor)
            Floor = root->data;
    }
    for(Treenode<int>* node: root->children)
    {
        CeilFloor(node,data);
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
    CeilFloor(root,data);
    cout<<"Floor: "<<Floor<<endl;
    cout<<"Ceil: "<<Ceil<<endl;
    cout<<endl;
	return 0;
}

