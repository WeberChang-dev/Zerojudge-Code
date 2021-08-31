#include<iostream>
using namespace std;
int main()
{
    int t,a,b,c,d;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin >> a >> b >> c >> d;
        if((b-a)==(c-b)&&(c-b)==(d-c))
        {
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d+(c-b)<<endl;
        }
         else if((b/a)==(c/b)&&(c/b)==(d/c))
        {
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d*(c/b)<<endl;
        }
    }
}
