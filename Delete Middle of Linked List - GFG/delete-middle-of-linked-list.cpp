//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends


/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
  int count(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while (temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

Node* deleteMid(Node* head)
{
    // Your Code Here
     Node* first = head;
    Node* second = head;
     if (head == NULL || head->next == NULL ) { 
        return NULL;
    }
    if (count(head) % 2 != 0) { 
        while (second->next != NULL && second->next->next->next != NULL) { 
            first = first->next;
            second = second->next->next;
        }
        first->next = first->next->next;
    } else {
        while (second->next != NULL && second->next->next != NULL) {
            first = first->next;
            second = second->next->next;
        }
        first->next = first->next->next;
    }
    return head;
}