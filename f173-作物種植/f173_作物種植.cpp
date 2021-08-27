#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
pair<int,int> arr[10005];
int m,t,dp[10005]={},ans=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>m>>t;
    for(int i=0;i<t;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+t);
    for(int i=0;i<t;i++)
    {
        for(int j=m;j>=0;j--)
        {
            if(j<=arr[i].first)
            {
                dp[arr[i].second]=max(dp[arr[i].second],dp[j]+(arr[i].second-arr[i].first));
            }
        }
    }
    for(int i=0;i<=m;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
