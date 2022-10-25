//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
          vector<int>ans;
          map<int,int>c;
          vector<int>v;
          map<int,int>mpp;

          for(int i=0;i<n1;i++){
              mpp[A[i]]++;
          }

         for(int i=0;i<n2;i++){
             int temp=B[i];
             if(mpp.find(temp)!=mpp.end())
                 v.push_back(temp);
         }

         mpp.clear();

         for(int i=0;i<n3;i++){
             mpp[C[i]]++;
         }

         for(int i=0;i<v.size();i++){
             int temp=v[i];
             if(mpp.find(temp)!=mpp.end())
             c[temp]++;
         }

         for(auto it:c){
             ans.push_back(it.first);
         }

         return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends