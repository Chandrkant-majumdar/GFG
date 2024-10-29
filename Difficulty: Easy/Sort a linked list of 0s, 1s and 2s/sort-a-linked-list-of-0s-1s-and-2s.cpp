//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        
        if(!head || !head->next) return head;

        Node* zeroH=new Node(-1),*zero=zeroH;
        Node* oneH=new Node(-1),*one=oneH;
        Node* twoH=new Node(-1),*two=twoH;
        Node *t=head;
        while(t){
            if(t->data==0){
                zero->next=t;
                zero=zero->next;
            }
            else if(t->data==1){
                one->next=t;
                one=one->next;
            }else{
                two->next=t;
                two=two->next;
            }
            t=t->next;
        }
        zero->next=(oneH->next)?oneH->next:twoH->next;
        one->next=twoH->next;
        two->next=nullptr;
        
        return head=zeroH->next;
    }
    Node* segregate1(Node* head) {

        // Add code here
        vector<int>ans;
        Node* t=head;
        while(t){
            ans.push_back(t->data);
            t=t->next;
        }
        sort(ans.begin(),ans.end());
        t=head;
        int i=0;
        while(t){
           t->data=ans[i++];
            t=t->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends