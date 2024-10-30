//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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

class Solution {
  public:
   Node * rev(Node *head){
       Node *p=NULL,*cur=head,*front=head;
       while(cur){
           front=cur->next;
           cur->next=p;
           p=cur;
           cur=front;
       }
       return p;
   }
    Node* addOne(Node* head) {
        
        head=rev(head);
        Node *t=head;
        int c=1;
        while(t){
            if(t->data+c>=10){
                c=1;
                t->data=0;
            }else{
                
                t->data=t->data+c;
                c=0;
                break;
            }
            t=t->next;
        }
        head=rev(head);
        if(c){
            Node* newH=new Node(1);
            newH->next=head;
            return newH;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends