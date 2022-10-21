//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)

 {
     vector<int> n;
     n=nums;
     sort(n.begin(),n.end());

     unordered_map<int,int> mpp;
     for(int i=0;i<n.size();i++) mpp[n[i]]=i;
     int count=0;
     for(int i=0;i<nums.size();i++)
     {
         if(mpp[nums[i]]==i) continue;
         else
         {
             count++;
             swap(nums[i],nums[mpp[nums[i]]]);
             i--;
         }

     }
     return count;

 }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends