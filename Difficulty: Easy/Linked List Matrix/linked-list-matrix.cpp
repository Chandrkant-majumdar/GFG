//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
     Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        
        if(mat.empty())return nullptr;
        int m=mat.size();
        int n=mat[0].size();
    
    //step-1 filling elements in linkedlist
        Node* nodematrix[n][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // Incorrect: Just assigning an integer value, no node object is created
            // nodematrix[i][j] = mat[i][j]
            nodematrix[i][j]=new Node(mat[i][j]);
        }
    }
    
    //step-2 linking (right and down)
    
     // Step 2: Link the nodes (right and down)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j + 1 < n) {
                    nodematrix[i][j]->right = nodematrix[i][j + 1];  // Link to the right node
                }
                if (i + 1 < m) {
                    nodematrix[i][j]->down = nodematrix[i + 1][j];  // Link to the down node
                }
            }
        }
        
        // Return the head of the linked matrix (top-left node)
        return nodematrix[0][0];
    }
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends