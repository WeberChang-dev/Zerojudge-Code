#include<iostream>
using namespace std;
int main()
{
   int a;
   while(cin>>a)
   {
       
       if(a%4==0) //沒辦法整除4一定是平年
       {
           if(a%100==0) //被4整除中 只有能被100整除才有可能是平年 先排除
           {
               if(a%400==0) //能整除400即是閏年
               {
                   cout<<"閏年"<<endl;
               }
               else
               {
                   cout<<"平年"<<endl;
               }
           }
           else
           {
               cout<<"閏年"<<endl;
           }
       }
       else
       {
           cout<<"平年"<<endl;
       }
   }
}
