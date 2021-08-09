#include<iostream>
using namespace std;
int n,v;
struct BSTnode
{
    struct BSTnode *leftkid;
    struct BSTnode *rightkid;
    int value;
};
void preorder(BSTnode *current)
{
    if(current==NULL) return;
    cout<<current->value<<" ";
    preorder(current->leftkid);
    preorder(current->rightkid);
}
void insert_node(BSTnode *current,BSTnode *target)
{
    if(current->value>target->value)
    {
        if(current->leftkid==NULL) current->leftkid=target;
        else insert_node(current->leftkid,target);
    }
    else
    {
        if(current->rightkid==NULL) current->rightkid=target;
        else insert_node(current->rightkid,target);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin>>n)
    {
        n--;
        cin>>v;
        BSTnode *origin;
        origin= new BSTnode;
        origin->value=v;
        origin->rightkid=NULL;
        origin->leftkid=NULL;
        while(n--)
        {
            BSTnode *newnode;
            newnode= new BSTnode;
            cin>>v;
            newnode->value=v;
            insert_node(origin,newnode);
        }
        preorder(origin);
        cout<<"\n";
    }
    return 0;
}
