//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        queue<int>pos,neg;
        for(auto &i:arr) i<0 ?neg.push(i):pos.push(i);
        int ind=0;
        while(!pos.empty() || !neg.empty()){
            if(!pos.empty()) {
                arr[ind++]=pos.front();
                pos.pop();
            }
             if(!neg.empty()){
                 arr[ind++]=neg.front();
                  neg.pop();
             }
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends