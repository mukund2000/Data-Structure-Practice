#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *deleteNode(Node *head, int pos)
{
    Node *temp=head;
    int i=0;
    if(pos==0)
    {
        temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    while(temp->next!=NULL)
    {
        if(pos-1==i)
        {
            Node *temp1=temp->next;
            temp->next=temp1->next;
            delete temp1;
            break;
        }
        else
        {
            i++;
        	temp=temp->next;
        }
	}
    return head;
    //Write your code here
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}
