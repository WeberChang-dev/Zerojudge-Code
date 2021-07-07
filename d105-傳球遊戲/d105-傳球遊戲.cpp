#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll dp2[n]={},dp1[n]={};
    dp1[0]=dp2[0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp2[j]=dp1[(j-1+n)%n]+dp1[(j+1)%n];
        }
        for(int j=0;j<n;j++)
        {
            dp1[j]=dp2[j];
        }
    }
    cout<<dp2[0];
}
