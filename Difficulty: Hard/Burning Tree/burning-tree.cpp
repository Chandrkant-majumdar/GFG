//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node * f(int target,map<Node *,Node *>&pt,Node *root){
        // if(root)
        queue<Node *>q;
        Node *temp;
        q.push(root);
        while(!q.empty()){
            Node *cur=q.front();
            if(cur->data==target){
                temp=cur;
            }
            int size=q.size();
             q.pop();
            if(cur->left){
                pt[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                pt[cur->right]=cur;
                q.push(cur->right);
            }
            
        }
        return temp;
    }
    int fd(map<Node *,Node *>&pt,Node *target){
        queue<Node *>q;
        int maxi=0;
        map<Node*,bool>vis;
        vis[target]=1;
        q.push(target);
        while(!q.empty()){
            int fi=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *temp=q.front();
                q.pop();
                if(temp->left &&!vis[temp->left]){
                    fi=1;
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right && !vis[temp->right]){
                    fi=1;
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(pt[temp] &&!vis[pt[temp]]){
                    fi=1;
                    q.push(pt[temp]);
                    vis[pt[temp]]=true;
                }
            }
            if(fi==1) maxi++;
        }
        return maxi;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node *,Node *>pt;
        Node *t=f(target,pt,root);
        int maxi=fd(pt,t);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends