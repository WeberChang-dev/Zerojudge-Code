#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,l;
    cin>>n>>l;
    int order[n]={};
    vector<int> spot;
    spot.push_back(0); spot.push_back(l);
    long long sum=0;
    for(int i=1;i<n+1;i++)
    {
        int a,b;
        cin>>a>>b;
        order[b-1]=a;
    }
    for(int i=0;i<n;i++)
    {
        int right=spot.size()-1,left=0;
        bool flag=false;
        while(right>=left&&!flag)
        {
            int mid=(left+right)/2;
            if(spot[mid]>order[i]) right=mid-1;
            else left=mid+1;
        }
        sum+=(spot[left]-spot[left-1]);
        spot.insert(spot.begin()+(left),order[i]);
    }
     cout<<sum;    
}
