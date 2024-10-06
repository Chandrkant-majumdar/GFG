//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long s=0,sn=(n*(n+1))/2;
        long long s2=0,s2n=(n*(n+1)*(2*n+1))/6;
        for(auto x:arr){
            s+=x;
        long long t=(long long)x*(long long)x;
            s2+=t;
        }
        long long res1=(s-sn);
        long long res2=(s2-s2n);
        res2=res2/res1;
        long long x=(res1+res2)/2;
        long long y=x-res1;
        return {(int)x,(int)y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends