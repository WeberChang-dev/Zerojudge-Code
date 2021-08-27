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
    arr[0].first=arr[0].second=0;
    for(int i=1;i<=t;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+t);
    for(int i=0;i<=t;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(arr[j].second<=arr[i].first)
            {
                dp[arr[i].second]=max(dp[arr[i].second],dp[arr[j].second]+(arr[i].second-arr[i].first));
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
