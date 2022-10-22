//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> presum;
        int sum = 0; 
        int mlen = 0;
        
        for (int i = 0; i < n; i++){
            sum += A[i];
            if (sum == 0) mlen = i + 1;
            if (presum.find(sum) != presum.end()){
                mlen = max(mlen, i - presum[sum]);
            }
            else presum[sum]=i;
        }
        return mlen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends