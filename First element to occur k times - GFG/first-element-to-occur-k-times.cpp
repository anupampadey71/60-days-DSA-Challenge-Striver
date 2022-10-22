//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        if(k==1){
            return a[0];
        }

        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(a[i])!=m.end() and m[a[i]]==k-1){
                return a[i];
            }
            m[a[i]]++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends