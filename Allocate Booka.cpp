#include <bits/stdc++.h>
using namespace std;
bool isPossible(int n, int m, vector<int> time,long long int mid)
{
    int DayCount=1;
    long long int TimeSum=0;
    for(int i=0;i<m;i++)
    {
        if(TimeSum + time[i] <= mid)
            TimeSum+=time[i];
        else{
            DayCount++;
            if(DayCount>n || time[i]>mid)
                return false;
        
    
           TimeSum=time[i];
        }        
        if (DayCount>m)
        {
            return false;
        }
        
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long ans=-1;
    long long int sum=0;
    long long int s=0;
    for(int i=0;i<m;i++)
    {
        sum+=time[i];
    }
    long long int e=sum;
    long long int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(isPossible(n,m,time,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}