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

void LevelOrder(Treenode<int>* root)
{
    queue<Treenode<int>* > pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        cout<<pending.front()->data<<" ";
        for(Treenode<int>* node: pending.front()->children)
        {
            pending.push(node);
        }
        pending.pop();
    }
}
void LevelOrderLineWise(Treenode<int>* root)
{
    queue<Treenode<int>* > mq;
    queue<Treenode<int>* > cq;
    mq.push(root);
    while(mq.size()>0)
    {
        cout<<mq.front()->data<<" ";
        for(Treenode<int>* node: mq.front()->children)
        {
            cq.push(node);
        }
        mq.pop();
        if(mq.size()==0)
        {
            mq.swap(cq);
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
	LevelOrder(root);
	cout<<endl;
	LevelOrderLineWise(root);
	return 0;
}



