//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
         string UncommonChars(string A, string B)

        {
          int m = A.size();
          int n = B.size();
          map<char,int>mp,np;
          for(int i=0;i<m;i++)
          {
              mp[A[i]]++;
          }

          for(int i=0;i<n;i++)
          {
              np[B[i]]++;
          }
          
          string ans = "";
          for(int i=0;i<n;i++)
          {
              if(mp.find(B[i])==mp.end())
              {

                  ans += B[i];
              }
          }

          for(int i=0;i<m;i++)
          {
              if(np.find(A[i])==np.end())
              {
                  ans += A[i];
              }
          }

          set<char>cp;
          for(int i=0;i<ans.size();i++)
          {
              cp.insert(ans[i]);
          }
          string lk="";
          for(auto i:cp)
            lk += i;
          if(ans.size()>0)
            return lk;
          else
            return "-1";
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends