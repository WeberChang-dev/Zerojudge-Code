#include<iostream>
#include<algorithm>
#include<utility>
int main()
{
    int n,r,l;
    std::pair<int,int> rope[10005];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&l,&r);
            rope[i]={l,r};
        }
        std::sort(rope,rope+n);
        int begin=-1,end=-1,ans=0;
        for(int i=0;i<=n;i++)
        {
            if(rope[i].first>end)
            {
                ans+=(end-begin);
                begin=rope[i].first;
                end=rope[i].second;
            }
            end=std::max(end,rope[i].second);
        }
        ans+=(end-begin);
        printf("%d\n",ans);
    }
}
