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
int ms = INT_MIN;
int msn = 0;
int SubTreeSum(Treenode<int>* root)
{
    int sum = 0;
    for(Treenode<int>* node : root->children)
    {
        int csum = SubTreeSum(node);
        sum+=csum;
    }
    sum+=root->data;
    if(sum>ms)
    {
        ms=sum;
        msn = root->data;
    }
    return sum;
}


int main() {
    vector<int> arr = {10,20,-50,-1,-60,-1,-1,30,-70,-1,80,-110,-1,120,-1,-1,90,-1,-1,40,-100,-1,-1,-1};
    Treenode<int>* root = Create(arr);
	display(root);
	cout<<endl;
	SubTreeSum(root);
    cout<<msn<<" node with maximum sum: "<<ms<<endl;
    cout<<endl;
	return 0;
}


