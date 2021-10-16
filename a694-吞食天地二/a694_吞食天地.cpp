#include<iostream>
#define ll long long
using namespace std;
ll n,m,arr[505][505]={},x1,x2,y1,y2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cin>>arr[i][j];
                //building two-dimensional prefix sum
                arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]; 
            }
        }
        for(int i=1;i<=m;++i)
        {
            cin>>x1>>y1>>x2>>y2;
            cout<<arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]<<'\n';
        }
    }
    return 0;
}
