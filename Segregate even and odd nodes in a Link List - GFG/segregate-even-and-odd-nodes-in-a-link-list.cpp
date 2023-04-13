//{ Driver Code Starts
//Initial template for C++

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
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* temp=head;
        
        Node* even_head=new Node(0);
        Node* evencurrent=even_head;
        
        Node* odd_head=new Node(0);
        Node* oddcurrent=odd_head;
        
        
        while(temp!=NULL){
            if((temp->data )%2==0){
                evencurrent->next=temp;
                evencurrent=evencurrent->next;
            }else{
                oddcurrent->next=temp;
                oddcurrent=oddcurrent->next;
            }
            temp=temp->next;
        }
        evencurrent->next=odd_head->next;
        oddcurrent->next=NULL;
        Node* res=even_head->next;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends