#include <iostream>
#include<algorithm>
using namespace std;
typedef struct node
{
    int prev;
    int next;
}cut;
cut arr[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,l,a,b;
    long long sum=0;
    cin>>n>>l;
    int order[n],spot[n+2];
    spot[0]=0;
    spot[n+1]=l;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        spot[i+1]=a;
        order[b-1]=a;
        arr[i+1].prev=i;
        arr[i+1].next=i+2;
    }
    sort(spot,spot+(n+2));
    for(int i=n-1;i>=0;i--)
    {
        int right=n+1,left=0,mid;
        while(right>=left)
        {
            mid=(left+right)/2;
            if(spot[mid]==order[i]) break;
            else if(spot[mid]>order[i]) right=mid-1;
            else left=mid+1;
        }
        sum+=(spot[arr[mid].next]-spot[arr[mid].prev]);
        arr[arr[mid].next].prev=arr[mid].prev;
        arr[arr[mid].prev].next=arr[mid].next;
    }
    cout<<sum;
}
