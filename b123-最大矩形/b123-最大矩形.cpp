#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
       int arr[n][m],ans=-1,width=1000;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>arr[i][j];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!arr[i][j]) continue;
                width=1000;
                for(int k=i;k<n;k++)
                {
                    int height=k-i+1;
                    for(int l=j;l<m;l++)
                    {
                        if(!arr[k][l])
                        {
                            width=min(width,l-j);
                            ans=max(ans,height*width);
                        }
                        else if(l==m-1)
                        {
                            width=min(width,l-j+1);
                            ans=max(ans,height*width);
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n'; 
    }
}
