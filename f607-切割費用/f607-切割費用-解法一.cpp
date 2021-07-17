#include<iostream>
#include<set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,l;
    cin>>n>>l;
    int order[n]={};
    int spot1[n+2]={};
    spot1[n+1]=l;
    long long sum=0;
    for(int i=1;i<n+1;i++)
    {
        int a,b;
        cin>>a>>b;
        spot1[i]=a;
        order[b-1]=a;
    }
    set <int> spot(spot1,spot1+(n+2));
    for(int i=n-1;i>=0;i--)
    {
        set<int>::iterator pos=spot.find(order[i]);
        sum+=(*next(pos) - *prev(pos));
        spot.erase(order[i]);
    }
    cout<<sum;
}
