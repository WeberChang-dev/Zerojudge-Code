#include <iostream>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int n=s1.length(),m=s2.length(),t=s3.length();
    int dp[105][105][105]={};
    pair<int,int> pre[n+1][m+1]={};
    for(int i=0;i<=n;i++) dp[i][0][0]=0;
    for(int i=0;i<=m;i++) dp[0][i][0]=0;
    for(int i=0;i<=t;i++) dp[0][0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=t;k++)
            {
                if(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1])
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else
                {
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    cout<<dp[n][m][t];
}
