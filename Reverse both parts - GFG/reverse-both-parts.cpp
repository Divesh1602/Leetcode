//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   Node* rev(Node* head){
       Node* curr=head,*prev=NULL;
       while(curr){
           Node* next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
       }
       return prev;
   }
    Node *reverse(Node *head, int k)
    {
        // code here
        k--;
        Node* curr=head;
        while(curr)
        {
            if(k==0)
            break;
            curr=curr->next;
            k--;
        }
        Node* next=curr->next;
        curr->next=NULL;
        head=rev(head);
        next=rev(next);
        curr=head;
        while(curr->next)
        curr=curr->next;
        curr->next=next;
        return head;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends