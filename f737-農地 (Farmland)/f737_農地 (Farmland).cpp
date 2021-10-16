#include<iostream>
#define ll long long
using namespace std;
ll n,farm[3001][3001]={},u,ans=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>u;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>farm[i][j];
            if(farm[i][j]==-1) farm[i][j]=1000000005;
            //building two-dimensional prefix sum
            farm[i][j]+=farm[i-1][j]+farm[i][j-1]-farm[i-1][j-1]; 
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=ans+1;i+k<=n && j+k<=n && farm[i+k][j+k]-farm[i][j+k]-farm[i+k][j]+farm[i][j]<=u;++k)
            {
                    ans=k;
            }
        }
    }
    cout<<ans*ans;
    return 0;
}
