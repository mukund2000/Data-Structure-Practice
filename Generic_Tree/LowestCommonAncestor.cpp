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

vector<int> NodeToRoot(Treenode<int>* root,int key)
{
    if(root->data==key)
    {
        vector<int> ans;
        ans.push_back(root->data);
        return ans;
    }
    for(Treenode<int>* node: root->children)
    {
        vector<int> ptc = NodeToRoot(node,key);
        if(ptc.size()>0)
        {
            ptc.push_back(root->data);
            return ptc;
        }
    }
    return vector<int>();
}
int LCA(Treenode<int>* root,int d1,int d2)
{
    vector<int> p = NodeToRoot(root,d1);
    vector<int> q = NodeToRoot(root,d2);
    int i=p.size()-1,j=q.size()-1;
    while(i>=0 and j>=0 and p[i]==q[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    return p[i];
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
	cout<<"Enter Lowest common ancestor between two keys: ";
	int d1,d2;
	cin>>d1>>d2;
    int ans = LCA(root,d1,d2);
    cout<<ans;
    cout<<endl;
	return 0;
}


