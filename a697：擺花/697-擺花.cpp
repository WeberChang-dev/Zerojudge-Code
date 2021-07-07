#include <iostream>
using namespace std;
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ull dp[m+5]={};
    int a[n];
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=m;j>=0;j--)
        {
            for(int k=1;k<=a[i];k++)
            {
                if(j+k<=m) 
                {
                    dp[j+k]+=dp[j];
                    dp[j+k]%=1000007;
                }
            }
        }
    }
    cout<<dp[m];
}
