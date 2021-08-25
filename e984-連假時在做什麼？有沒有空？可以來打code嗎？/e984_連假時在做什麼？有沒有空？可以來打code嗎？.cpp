#include<iostream>
#include<string>
using namespace std;
int k,tail=10;
string dp[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>k;
    for(int i=1;i<10;i++)
        dp[i]=to_string(i);
    for(int i=1;tail<=k;i++)
    {
        int num=dp[i][dp[i].length()-1]-'0';
        if(num-1>=0)
        {
            dp[tail]=dp[i]+to_string(num-1);
            tail++;
        }
        dp[tail]=dp[i]+to_string(num);
        tail++;
        if(num+1<=9)
        {
            dp[tail]=dp[i]+to_string(num+1);
            tail++;
        }
    }
    cout<<dp[k];
    return 0;
}
