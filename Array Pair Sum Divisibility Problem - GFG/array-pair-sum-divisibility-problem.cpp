//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> v, int k) {
        if(v.size()%2==1 || accumulate(v.begin(), v.end(), 0)%k!=0) return false;
        unordered_map<int, int> mpp;
        for(int i=0; i<v.size(); i++){
            v[i] = v[i]%k;
            mpp[v[i]]++;
        }
        for(int i=0; i<v.size(); i++) 
        if(mpp[v[i]])
        {
            if(v[i])
            {
                mpp[v[i]]--;
                if(!(mpp.find(k-v[i])!=mpp.end() && mpp[k-v[i]])) return false;
                else mpp[k-v[i]]--;
            }
            else
            {
                mpp[0]--;
                if(!(mpp.find(0)!=mpp.end() && mpp[0])) return false;
                else mpp[0]--;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends