//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {

        int n = arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = k - arr[i]-arr[j];
                int s = j+1;
                int e = n-1;

                while(s<e)
                {
                    int two_sum = arr[s]+arr[e];
                    if(two_sum<sum)
                        s++;
                    else if(two_sum>sum)
                        e--;
                     else
                     {
                         vector<int>temp(4,0);
                         temp[0] = arr[i];
                         temp[1] = arr[j];
                         temp[2] = arr[s];
                         temp[3] = arr[e];
                         ans.push_back(temp);
                         while(s<e && arr[s]==temp[2])
                            s++;
                         while(s<e && arr[e]==temp[3])
                            e--;
                     }
                     while(j+1<n && arr[j]==arr[j+1])
                       j++;
                }

                

                while(i+1<n && arr[i]==arr[i+1])
                    i++;
            }
        }
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends