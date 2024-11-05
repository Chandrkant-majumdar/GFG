//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        if(!head) {
            Node *t=new Node;
            t->data=x;
            t->prev=NULL;
            t->next=NULL;
            return t;
        }
        Node *t=head,*p=head;
        while(t){
            if(p->next) p=p->next; 
            if(t->data>x){
                
                if(t==head){
                    Node *temp=new Node;
                    temp->data=x;
                    temp->prev=nullptr;
                    temp->next=head;
                    head->prev=temp;
                    return temp;
                }else{
                    Node *p=t->prev;
                    Node *temp=new Node;
                    temp->data=x;
                    p->next=temp;
                    temp->prev=p;
                    temp->next=t;
                    t->prev=temp;
                    return head;
                    
                }
            }else{
                t=t->next;
            }
        }
       
        // while(p) p=p->next;
        Node *temp=new Node;
        temp->data=x;
        temp->next=NULL;
        p->next=temp;
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends