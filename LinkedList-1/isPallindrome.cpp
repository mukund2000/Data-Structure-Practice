/*You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
*/


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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}


Node* ReverseLL(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    Node* curr=head;
    Node* prev=NULL;
    Node* fwd=NULL;
    while(curr!=NULL)
    {
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    // base condition
    if(head==NULL||head->next==NULL)
        return true;
    // finding mid point of the ll
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    // creating new ll after finding mid element
    Node* secondHead=slow->next;
    slow->next=NULL;
    secondHead=ReverseLL(secondHead);

    // creating two sublists for comparing
    Node* firstSub=head;
    Node* secondSub=secondHead;
    bool ans=true;

    while(secondSub!=NULL)
    {
        if(firstSub->data!=secondSub->data)
        {
            ans=false;
            break;
        }
        firstSub=firstSub->next;
        secondSub=secondSub->next;
    }

    // Rejoin two sublist
    firstSub=head;
    secondSub=ReverseLL(secondHead);

    while(firstSub->next!=NULL)
    {
        firstSub=firstSub->next;
    }
    firstSub->next=secondSub;
    return ans;
    //Write your code here
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}
/* Time Complexity:O(N)
    Space Complexity:O(1)
    */
